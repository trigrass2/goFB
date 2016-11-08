-- This file has been automatically generated by go-iec61499-vhdl and should not be edited by hand
-- Converter written by Hammond Pearce and available at github.com/kiwih/go-iec61499-vhdl

-- This file represents the Basic Function Block for InjectorPumpsController

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;



entity InjectorPumpsController is

	port(
		--for clock and reset signal
		clk		: in	std_logic;
		reset	: in	std_logic;
		enable	: in	std_logic;
		sync	: in	std_logic;
		
		--input events
		StartPump : in std_logic;
		EmergencyStopChanged : in std_logic;
		CanisterPressureChanged : in std_logic;
		FillContentsAvailableChanged : in std_logic;
		VacuumTimerElapsed : in std_logic;
		
		
		--output events
		PumpFinished : out std_logic;
		RejectCanister : out std_logic;
		InjectorControlsChanged : out std_logic;
		FillContentsChanged : out std_logic;
		StartVacuumTimer : out std_logic;
		
		
		--input variables
		EmergencyStop_I : in std_logic; --type was BOOL
		CanisterPressure_I : in unsigned(7 downto 0); --type was BYTE
		FillContentsAvailable_I : in unsigned(7 downto 0); --type was BYTE
		
		
		--output variables
		InjectorContentsValveOpen_O : out std_logic; --type was BOOL
		InjectorVacuumRun_O : out std_logic; --type was BOOL
		InjectorPressurePumpRun_O : out std_logic; --type was BOOL
		FillContents_O : out std_logic; --type was BOOL
		
		
		--for done signal
		done : out std_logic
	);

end entity;


architecture rtl of InjectorPumpsController is
	-- Build an enumerated type for the state machine
	type state_type is (STATE_RejectCanister, STATE_AwaitPump, STATE_VacuumPump, STATE_FinishPump, STATE_StartPump, STATE_OpenValve, STATE_StopVacuum);

	-- Register to hold the current state
	signal state   : state_type := STATE_RejectCanister;

	-- signals to store variable sampled on enable 
	signal EmergencyStop : std_logic := '0'; --register for input
	signal CanisterPressure : unsigned(7 downto 0) := (others => '0'); --register for input
	signal FillContentsAvailable : unsigned(7 downto 0) := (others => '0'); --register for input
	
	-- signals to rename outputs 
	signal InjectorContentsValveOpen : std_logic := '0'; 
	signal InjectorVacuumRun : std_logic := '0'; 
	signal InjectorPressurePumpRun : std_logic := '0'; 
	signal FillContents : std_logic := '0'; 
	

	-- signals for enabling algorithms	
	signal StartVacuum_alg_en : std_logic := '0'; 
	signal StartVacuum_alg_done : std_logic := '1';
	
	signal ClearControls_alg_en : std_logic := '0'; 
	signal ClearControls_alg_done : std_logic := '1';
	
	signal OpenValve_alg_en : std_logic := '0'; 
	signal OpenValve_alg_done : std_logic := '1';
	
	signal StartPump_alg_en : std_logic := '0'; 
	signal StartPump_alg_done : std_logic := '1';
	

	-- signal for algorithm completion
	signal AlgorithmsStart : std_logic := '0';
	signal AlgorithmsDone : std_logic;

	
begin
	-- Registers for data variables (only updated on relevant events)
	process (clk)
	begin
		if rising_edge(clk) then
			if sync = '1' then
				
				if EmergencyStopChanged = '1' then
					EmergencyStop <= EmergencyStop_I;
				end if;
				
				if CanisterPressureChanged = '1' then
					CanisterPressure <= CanisterPressure_I;
				end if;
				
				if FillContentsAvailableChanged = '1' then
					FillContentsAvailable <= FillContentsAvailable_I;
				end if;
				
			end if;
		end if;
	end process;
	
	--output var renaming, no output registers as inputs are stored where they are processed
	InjectorContentsValveOpen_O <= InjectorContentsValveOpen;
	InjectorVacuumRun_O <= InjectorVacuumRun;
	InjectorPressurePumpRun_O <= InjectorPressurePumpRun;
	FillContents_O <= FillContents;
			
	
	-- Logic to advance to the next state
	process (clk, reset)
	begin
		if reset = '1' then
			state <= STATE_RejectCanister;
			AlgorithmsStart <= '1';
		elsif (rising_edge(clk)) then
			if AlgorithmsStart = '1' then --algorithms should be triggered only once via this pulse signal
				AlgorithmsStart <= '0';
			elsif enable = '1' then 
				--default values
				state <= state;
				AlgorithmsStart <= '0';

				--next state logic
				if AlgorithmsStart = '0' and AlgorithmsDone = '1' then
					case state is
						when STATE_RejectCanister =>
							if true then
								state <= STATE_AwaitPump;
								AlgorithmsStart <= '1';
							end if;
						when STATE_AwaitPump =>
							if StartPump = '1' then
								state <= STATE_VacuumPump;
								AlgorithmsStart <= '1';
							end if;
						when STATE_VacuumPump =>
							if VacuumTimerElapsed = '1' then
								state <= STATE_RejectCanister;
								AlgorithmsStart <= '1';
							elsif CanisterPressureChanged = '1' and (CanisterPressure<=10) then
								state <= STATE_StopVacuum;
								AlgorithmsStart <= '1';
							end if;
						when STATE_FinishPump =>
							if true then
								state <= STATE_AwaitPump;
								AlgorithmsStart <= '1';
							end if;
						when STATE_StartPump =>
							if CanisterPressureChanged = '1' and (CanisterPressure>=245) then
								state <= STATE_FinishPump;
								AlgorithmsStart <= '1';
							end if;
						when STATE_OpenValve =>
							if true then
								state <= STATE_StartPump;
								AlgorithmsStart <= '1';
							end if;
						when STATE_StopVacuum =>
							if true then
								state <= STATE_OpenValve;
								AlgorithmsStart <= '1';
							end if;
						
					end case;
				end if;
			end if;
		end if;
	end process;

	-- Event outputs and internal algorithm triggers depend solely on the current state
	process (state)
	begin
		--default values
		--events
		PumpFinished <= '0';
		RejectCanister <= '0';
		InjectorControlsChanged <= '0';
		FillContentsChanged <= '0';
		StartVacuumTimer <= '0';
		
		--algorithms
		StartVacuum_alg_en <= '0'; 
		ClearControls_alg_en <= '0'; 
		OpenValve_alg_en <= '0'; 
		StartPump_alg_en <= '0'; 

		case state is
			when STATE_RejectCanister =>
				ClearControls_alg_en <= '1';
				RejectCanister <= '1';
				InjectorControlsChanged <= '1';
				
			when STATE_AwaitPump =>
				PumpFinished <= '1';
				
			when STATE_VacuumPump =>
				StartVacuum_alg_en <= '1';
				InjectorControlsChanged <= '1';
				StartVacuumTimer <= '1';
				
			when STATE_FinishPump =>
				ClearControls_alg_en <= '1';
				InjectorControlsChanged <= '1';
				
			when STATE_StartPump =>
				StartPump_alg_en <= '1';
				InjectorControlsChanged <= '1';
				
			when STATE_OpenValve =>
				OpenValve_alg_en <= '1';
				InjectorControlsChanged <= '1';
				
			when STATE_StopVacuum =>
				ClearControls_alg_en <= '1';
				InjectorControlsChanged <= '1';
				
			
		end case;
	end process;

	-- Algorithms process
	process(clk)
	begin
		if rising_edge(clk) then
			if AlgorithmsStart = '1' then			
				
				if StartVacuum_alg_en = '1' then -- Algorithm StartVacuum
					StartVacuum_alg_done <= '0';
				end if;
				
				if ClearControls_alg_en = '1' then -- Algorithm ClearControls
					ClearControls_alg_done <= '0';
				end if;
				
				if OpenValve_alg_en = '1' then -- Algorithm OpenValve
					OpenValve_alg_done <= '0';
				end if;
				
				if StartPump_alg_en = '1' then -- Algorithm StartPump
					StartPump_alg_done <= '0';
				end if;
				
			end if;

			
			if StartVacuum_alg_done = '0' then -- Algorithm StartVacuum

--begin algorithm raw text
InjectorVacuumRun <= '1';
 StartVacuum_alg_done <= '1';
--end algorithm raw text

			end if;
			
			if ClearControls_alg_done = '0' then -- Algorithm ClearControls

--begin algorithm raw text
InjectorContentsValveOpen <= '0';
 InjectorPressurePumpRun <= '0';
 InjectorVacuumRun <= '0';
 ClearControls_alg_done <= '1';
--end algorithm raw text

			end if;
			
			if OpenValve_alg_done = '0' then -- Algorithm OpenValve

--begin algorithm raw text
InjectorContentsValveOpen <= '1';
 OpenValve_alg_done <= '1';
--end algorithm raw text

			end if;
			
			if StartPump_alg_done = '0' then -- Algorithm StartPump

--begin algorithm raw text
InjectorPressurePumpRun <= '1';
 StartPump_alg_done <= '1';
--end algorithm raw text

			end if;
			
		end if;
	end process;

	--Done signal
	AlgorithmsDone <= (not AlgorithmsStart) and StartVacuum_alg_done and ClearControls_alg_done and OpenValve_alg_done and StartPump_alg_done;
	Done <= AlgorithmsDone;
end rtl;
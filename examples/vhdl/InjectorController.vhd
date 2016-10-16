-- This file has been automatically generated by go-iec61499-vhdl and should not be edited by hand
-- Converter written by Hammond Pearce and available at github.com/kiwih/go-iec61499-vhdl

-- This file represents the Composite Function Block for InjectorController

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;



entity InjectorController is

	port(
		--for clock and reset signal
		clk		: in	std_logic;
		reset	: in	std_logic;
		enable	: in	std_logic;
		sync	: in	std_logic;
		
		--input events
		InjectorArmFinishedMovement : in std_logic;
		EmergencyStopChanged : in std_logic;
		CanisterPressureChanged : in std_logic;
		FillContentsAvailableChanged : in std_logic;
		ConveyorStoppedForInject : in std_logic;
		VacuumTimerElapsed : in std_logic;
		
		
		--output events
		InjectDone : out std_logic;
		InjectorPositionChanged : out std_logic;
		InjectorControlsChanged : out std_logic;
		RejectCanister : out std_logic;
		FillContentsChanged : out std_logic;
		StartVacuumTimer : out std_logic;
		InjectRunning : out std_logic;
		
		
		--input variables
		EmergencyStop_I : in std_logic; --type was BOOL
		CanisterPressure_I : in unsigned(7 downto 0); --type was BYTE
		FillContentsAvailable_I : in unsigned(7 downto 0); --type was BYTE
		
		
		--output variables
		InjectorPosition_O : out unsigned(7 downto 0); --type was BYTE
		InjectorContentsValveOpen_O : out std_logic; --type was BOOL
		InjectorVacuumRun_O : out std_logic; --type was BOOL
		InjectorPressurePumpRun_O : out std_logic; --type was BOOL
		FillContents_O : out std_logic; --type was BOOL
		
		
		--for done signal
		done : out std_logic
	);

end entity;


architecture rtl of InjectorController is
	-- Signals needed for event connections 
	signal InjectorArmFinishedMovement_conn : std_logic;
	signal EmergencyStopChanged_conn : std_logic;
	signal CanisterPressureChanged_conn : std_logic;
	signal FillContentsAvailableChanged_conn : std_logic;
	signal ConveyorStoppedForInject_conn : std_logic;
	signal VacuumTimerElapsed_conn : std_logic;
	signal Arm_InjectDone_conn : std_logic;
	signal Arm_InjectorPositionChanged_conn : std_logic;
	signal Pumps_InjectorControlsChanged_conn : std_logic;
	signal Pumps_RejectCanister_conn : std_logic;
	signal Pumps_FillContentsChanged_conn : std_logic;
	signal Pumps_StartVacuumTimer_conn : std_logic;
	signal Arm_InjectRunning_conn : std_logic;
	signal Arm_StartPump_conn : std_logic;
	signal Pumps_PumpFinished_conn : std_logic;

	-- Signals needed for data connections 
	signal EmergencyStop_conn : std_logic; --type was BOOL
	signal CanisterPressure_conn : unsigned(7 downto 0); --type was BYTE
	signal FillContentsAvailable_conn : unsigned(7 downto 0); --type was BYTE
	signal Arm_InjectorPosition_conn : unsigned(7 downto 0); --type was BYTE
	signal Pumps_InjectorContentsValveOpen_conn : std_logic; --type was BOOL
	signal Pumps_InjectorVacuumRun_conn : std_logic; --type was BOOL
	signal Pumps_InjectorPressurePumpRun_conn : std_logic; --type was BOOL
	signal Pumps_FillContents_conn : std_logic; --type was BOOL

	-- Signals needed for the done signals 
	signal Arm_done : std_logic;
	signal Pumps_done : std_logic;
begin
	--top level I/O to signals
	--input events
	InjectorArmFinishedMovement_conn <= InjectorArmFinishedMovement;
	EmergencyStopChanged_conn <= EmergencyStopChanged;
	EmergencyStopChanged_conn <= EmergencyStopChanged;
	CanisterPressureChanged_conn <= CanisterPressureChanged;
	FillContentsAvailableChanged_conn <= FillContentsAvailableChanged;
	ConveyorStoppedForInject_conn <= ConveyorStoppedForInject;
	VacuumTimerElapsed_conn <= VacuumTimerElapsed;
	
	--output events
	InjectDone <= Arm_InjectDone_conn;
	InjectorPositionChanged <= Arm_InjectorPositionChanged_conn;
	InjectorControlsChanged <= Pumps_InjectorControlsChanged_conn;
	RejectCanister <= Pumps_RejectCanister_conn;
	FillContentsChanged <= Pumps_FillContentsChanged_conn;
	StartVacuumTimer <= Pumps_StartVacuumTimer_conn;
	InjectRunning <= Arm_InjectRunning_conn;
	
	--input variables
	EmergencyStop_conn <= EmergencyStop_I;
	EmergencyStop_conn <= EmergencyStop_I;
	CanisterPressure_conn <= CanisterPressure_I;
	FillContentsAvailable_conn <= FillContentsAvailable_I;
	
	--output events
	InjectorPosition_O <= Arm_InjectorPosition_conn;
	InjectorContentsValveOpen_O <= Pumps_InjectorContentsValveOpen_conn;
	InjectorVacuumRun_O <= Pumps_InjectorVacuumRun_conn;
	InjectorPressurePumpRun_O <= Pumps_InjectorPressurePumpRun_conn;
	FillContents_O <= Pumps_FillContents_conn;
	
	
	-- child I/O to signals
	
	Arm : entity work.InjectorMotorController port map(
		clk => clk,
		reset => reset,
		enable => enable,
		sync => sync,

		--event outputs 
		InjectDone => Arm_InjectDone_conn,
		InjectorPositionChanged => Arm_InjectorPositionChanged_conn,
		InjectRunning => Arm_InjectRunning_conn,
		StartPump => Arm_StartPump_conn,
		
		--event inputs
		InjectorArmFinishedMovement => InjectorArmFinishedMovement_conn, 
		EmergencyStopChanged => EmergencyStopChanged_conn, 
		ConveyorStoppedForInject => ConveyorStoppedForInject_conn, 
		PumpFinished => Pumps_PumpFinished_conn, 
		
		--data outputs
		InjectorPosition_O => Arm_InjectorPosition_conn, 
		
		--data inputs
		EmergencyStop_I => EmergencyStop_conn, --input
		

		
		done => Arm_done
	);
	
	Pumps : entity work.InjectorPumpsController port map(
		clk => clk,
		reset => reset,
		enable => enable,
		sync => sync,

		--event outputs 
		InjectorControlsChanged => Pumps_InjectorControlsChanged_conn,
		RejectCanister => Pumps_RejectCanister_conn,
		FillContentsChanged => Pumps_FillContentsChanged_conn,
		StartVacuumTimer => Pumps_StartVacuumTimer_conn,
		PumpFinished => Pumps_PumpFinished_conn,
		
		--event inputs
		EmergencyStopChanged => EmergencyStopChanged_conn, 
		CanisterPressureChanged => CanisterPressureChanged_conn, 
		FillContentsAvailableChanged => FillContentsAvailableChanged_conn, 
		VacuumTimerElapsed => VacuumTimerElapsed_conn, 
		StartPump => Arm_StartPump_conn, 
		
		--data outputs
		InjectorContentsValveOpen_O => Pumps_InjectorContentsValveOpen_conn, 
		InjectorVacuumRun_O => Pumps_InjectorVacuumRun_conn, 
		InjectorPressurePumpRun_O => Pumps_InjectorPressurePumpRun_conn, 
		FillContents_O => Pumps_FillContents_conn, 
		
		--data inputs
		EmergencyStop_I => EmergencyStop_conn, --input
		CanisterPressure_I => CanisterPressure_conn, --input
		FillContentsAvailable_I => FillContentsAvailable_conn, --input
		

		
		done => Pumps_done
	);
	

	-- done signal
	done <= Arm_done and Pumps_done;
	
end rtl;

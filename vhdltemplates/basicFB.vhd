{{define "basicFB"}}-- This file has been automatically generated by go-iec61499-vhdl and should not be edited by hand
-- Converter written by Hammond Pearce and available at github.com/kiwih/go-iec61499-vhdl
{{$block := index .Blocks .BlockIndex}}{{$blocks := .Blocks}}{{$basicFB := $block.BasicFB}}
-- This file represents the Basic Function Block for {{$block.Name}} (index .BlockIndex)

library ieee;
use ieee.std_logic_1164.all;
{{template "_entityFB" $block}}
architecture rtl of {{$block.Name}} is
	-- Build an enumerated type for the state machine
	type state_type is ({{range $index, $state := $basicFB.States}}{{if $index}}, {{end}}{{$state.Name}}{{end}});

	-- Register to hold the current state
	signal state   : state_type := {{(index $basicFB.States 0).Name}};

	-- signals for enabling algorithms	{{range $algIndex, $alg := $basicFB.Algorithms}}
	signal {{$alg.Name}}_alg_en : std_logic := '0'; 
	signal {{$alg.Name}}_alg_done : std_logic := '1';
	{{end}}

	-- signal for algorithm completion
	signal AlgorithmsStart : std_logic := '0';
	signal AlgorithmsDone : std_logic;

	{{if $basicFB.InternalVars}}--internal variables {{range $varIndex, $var := $basicFB.InternalVars.Variables}}
	signal {{$var.Name}} : {{getVhdlType $var.Type}}; --type was {{$var.Type}} {{end}}{{end}}
begin
	
	-- Logic to advance to the next state
	process (clk, reset)
	begin
		if reset = '1' then
			state <= {{(index $basicFB.States 0).Name}};
			AlgorithmsStart <= '1';
		elsif (rising_edge(clk)) then
			if AlgorithmsStart = '1' then --algorithms should be triggered only once via this pulse signal
				AlgorithmsStart <= '0'
			elsif enable = '1' then 
				--default values
				state <= state;
				AlgorithmsStart <= '0';

				--next state logic
				elsif AlgorithmsStart = '0' and AlgorithmsDone = '1' then
					case state is
						{{range $curStateIndex, $curState := $basicFB.States}}when {{$curState.Name}}=>
							{{range $transIndex, $trans := $basicFB.GetTransitionsForState $curState.Name}}{{if $transIndex}}els{{end}}if {{getVhdlECCTransitionCondition $trans.Condition}} then
								state <= {{$trans.Destination}};
								AlgorithmsStart <= '1';
							{{end}}end if;
						{{end}}
					end case;
				end if;
			end if;
		end if;
	end process;

	-- Event outputs and internal algorithm triggers depend solely on the current state
	process (state)
	begin
		--default values
		{{if $block.EventOutputs}}--events
		{{range $index, $event := $block.EventOutputs.Events}}{{$event.Name}} <= '0';
		{{end}}{{end}}
		{{if $basicFB.Algorithms}}--algorithms{{range $algIndex, $alg := $basicFB.Algorithms}}
		{{$alg.Name}}_alg_en <= '0'; {{end}}{{end}}

		case state is
			{{range $curStateIndex, $curState := $basicFB.States}}when {{$curState.Name}}=>
				{{range $actionIndex, $action := $curState.ECActions}}{{if $action.Algorithm}}{{$action.Algorithm}}_alg_en <= '1';
				{{end}}{{if $action.Output}}{{$action.Output}} <= '1';
				{{end}}{{end}}
			{{end}}
		end case;
	end process;

	{{if $basicFB.Algorithms}}-- Algorithms process
	process(clk)
	begin
		if rising_edge(clk) then
			if AlgorithmsStart = '1' then			
				{{range $algIndex, $alg := $basicFB.Algorithms}}
				if {{$alg.Name}}_alg_en = '1' then -- Algorithm {{$alg.Name}}
					{{$alg.Name}}_alg_done <= '0';
				end if;
				{{end}}
			end if;

			{{range $algIndex, $alg := $basicFB.Algorithms}}
			if {{$alg.Name}}_alg_done = '0' then -- Algorithm {{$alg.Name}}

--begin algorithm raw text
{{renameDoneSignal $alg.Other.Text $alg.Name}}
--end algorithm raw text

			end if;
			{{end}}
		end if;
	end process;{{else}}--This Basic FB had no algorithms
	{{end}}

	--Done signal
	AlgorithmsDone <= (not AlgorithmsStart){{if $basicFB.Algorithms}} and{{range $algIndex, $alg := $basicFB.Algorithms}}{{if $algIndex}} and{{end}} {{$alg.Name}}_alg_done{{end}}{{end}};
	Done <= AlgorithmsDone;
end rtl;
{{end}}
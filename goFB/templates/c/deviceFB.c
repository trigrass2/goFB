{{define "deviceFB"}}// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB
{{$block := index .Blocks .BlockIndex}}{{$blocks := .Blocks}}{{$deviceFB := $block}}
// This file represents the implementation of the Device Function Block for {{$block.Name}}
#include "FB_{{$block.Name}}.h"

//When running a composite block, note that you would call the functions in this order (and this is very important)
//_preinit(); 
//_init();
//do {
//	_syncOutputEvents();
//	_syncInputEvents();
//	_syncOutputData();
//	_syncInputData();
//	_run();
//} loop;


{{template "_fbinit" .}}

/* {{$block.Name}}_sync[Output/Input]Events() synchronises the events of an
 * instance of {{$block.Name}} as required by synchronous semantics.
 * Notice that it does NOT perform any computation - this occurs in the
 * _run function.
 */
void {{$block.Name}}_syncOutputEvents({{$block.Name}}_t {{if .TcrestUsingSPM}}_SPM{{end}} *me) {
	//for all device function block resource function blocks, call this same function
	//resources are the only things that can be embedded in devices
	{{range $currChildIndex, $child := $deviceFB.Resources}}//sync for {{$child.Name}} (of type {{$child.Type}}) which is a Resource
	{{$child.Type}}_syncOutputEvents(&me->{{$child.Name}});{{end}}
	
}
void {{$block.Name}}_syncInputEvents({{$block.Name}}_t {{if .TcrestUsingSPM}}_SPM{{end}} *me) {
	//for all device function block resource function blocks, call this same function
	//resources are the only things that can be embedded in devices
	{{range $currChildIndex, $child := $deviceFB.Resources}}//sync for {{$child.Name}} (of type {{$child.Type}}) which is a Resource
	{{$child.Type}}_syncInputEvents(&me->{{$child.Name}});{{end}}
	
}

/* {{$block.Name}}_sync[Output/Input]Data() synchronises the data connections of an
 * instance of {{$block.Name}} as required by synchronous semantics.
 * It does the checking to ensure that only connections which have had their
 * associated event fire are updated.
 * Notice that it does NOT perform any computation - this occurs in the
 * _run function.
 */
void {{$block.Name}}_syncOutputData({{$block.Name}}_t {{if .TcrestUsingSPM}}_SPM{{end}} *me) {
	//for all device function block resource function blocks, call this same function
	//resources are the only things that can be embedded in devices
	{{range $currChildIndex, $child := $deviceFB.Resources}}//sync for {{$child.Name}} (of type {{$child.Type}}) which is a Resource
	{{$child.Type}}_syncOutputData(&me->{{$child.Name}});{{end}}

}
void {{$block.Name}}_syncInputData({{$block.Name}}_t {{if .TcrestUsingSPM}}_SPM{{end}} *me) {
	//for all device function block resource function blocks, call this same function
	//resources are the only things that can be embedded in devices
	{{range $currChildIndex, $child := $deviceFB.Resources}}//sync for {{$child.Name}} (of type {{$child.Type}}) which is a Resource
	{{$child.Type}}_syncInputData(&me->{{$child.Name}});{{end}}

}


/* {{$block.Name}}_run() executes a single tick of an
 * instance of {{$block.Name}} according to synchronise semantics.
 * Notice that it does NOT perform any I/O - synchronisation
 * is done using the _syncX functions at this (and any higher) level.
 */
void {{$block.Name}}_run({{$block.Name}}_t {{if .TcrestUsingSPM}}_SPM{{end}} *me) {
	{{range $currChildIndex, $child := $deviceFB.Resources}}{{$child.Type}}_run(&me->{{$child.Name}});
	{{end}}
}

{{end}}
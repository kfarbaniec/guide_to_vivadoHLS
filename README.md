# Guide to Vivado HLS example design

Component to duplicate and perform basic image processing operations on video stream.
More information about hw accelerated image processing operations in Vivado HLS: 
http://www.wiki.xilinx.com/HLS+Video+Library


## REQUIREMENTS

No other cores dependencies.

## COMPILATON

Create and enter ./work directory and run:

```
vivado_hls -f ../scripts/create_project.tcl <project_name>
```

where project_name is the top level function name - here: copy_streamss

## NOTES

* The compile tcl script automatically generates IP Core at the end


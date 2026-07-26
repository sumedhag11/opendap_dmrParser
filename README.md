# opendap_dmr-parser

This repository contains a client side tool, opendap_dmr-parser, that queries datasets accessible via OPeNDAP. It reads the .dmr file (label file) for a given dataset, parses it, and displays the dataset schema in a human readable format. 
This tool has been tested against both THREDDS and Hyrax servers

### Sample usage

./opendap_dmr-parser describe https://thredds-test.unidata.ucar.edu/thredds/dap4/testdods/testData.nc.dmr
```

results in

```
    - reftime (reference time, hours since 1992-1-1) — shape [record=1]

    - valtime_offset (hours from reference time, hours) — shape [record=1]

    - La1 (latitude of first grid point, degrees_north) — shape [nav=1]

    - Lo1 (longitude of first grid point, degrees_east) — shape [nav=1]

    - Lov (orientation of the grid, degrees_east) — shape [nav=1]

    - Dx (x-direction grid length, km) — shape [nav=1]

    - Dy (y-direction grid length, km) — shape [nav=1]

    - Z_sfc (Geopotential height, gpm, gp m) — shape [record=1,y=95,x=135]

    - valtime (valid time, hours since 1992-1-1) — shape [record=1]

    - x (synthesized X coord, km) — shape [x=135]

    - y (synthesized Y coord, km) — shape [y=95]
```

# opendap_llmtool

This repository contains a client side tool, opendap_llmtool, that quries databases accessible via OPeNDAP. It reads the .dmr file (label file) for a given dataset, parses it, and displays the database schema in a human readable manner.

### Sample usage

```
./opendap-llmtool describe http://test.opendap.org/opendap/data/nc/coads_climatology.nc.dmr    
```

results in

```
    Variable name: COADSX, type: Float64, units: degrees_east, long_name: , size: 180
    Variable name: COADSY, type: Float64, units: degrees_north, long_name: , size: 90
    Variable name: TIME, type: Float64, units: hour since 0000-01-01 00:00:00, long_name: , size: 12
    Variable name: SST, type: Float32, units: Deg C, long_name: SEA SURFACE TEMPERATURE, size: -1
    Variable name: AIRT, type: Float32, units: DEG C, long_name: AIR TEMPERATURE, size: -1
    Variable name: UWND, type: Float32, units: M/S, long_name: ZONAL WIND, size: -1
    Variable name: VWND, type: Float32, units: M/S, long_name: MERIDIONAL WIND, size: -1
```

Another example with differently structured schema:

```
./opendap-llmtool describe https://thredds-test.unidata.ucar.edu/thredds/dap4/testdods/testData.nc.dmr
```

results in

```
    Command passed =describe, DEBUG url = https://thredds-test.unidata.ucar.edu/thredds/dap4/testdods/testData.nc.dmr
    status: 200
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

CSV Anomaly Detector
===================

CPP based implementation of csv cell anomaly dectector using histogram analysis.

Used only the STL, no third part library included.


How to build and run
--------------------
```bash
$ mkdir build && cd build
$ cmake ..
$ make

$ ./csv-anomaly-detector your.csv
```

TODO
----

1. Row wise anomaly reporting with info about which cell has problem.
2. Add more tests.

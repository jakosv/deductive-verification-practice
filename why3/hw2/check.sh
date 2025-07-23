#!/bin/sh

echo "====== ALT-EGRO SOLVER ======"
why3 prove -P alt-egro hw2.why 2>/dev/null
echo "======================="
echo "====== Z3 SOLVER ======"
echo "======================="
why3 prove -P z3 hw2.why 2>/dev/null
echo "=========================="
echo "====== Z3-CE SOLVER ======"
echo "=========================="
why3 prove -P z3-ce hw2.why 2>/dev/null
echo "============================"
echo "====== Z3-NOBV SOLVER ======"
echo "============================"
why3 prove -P z3-nobv hw2.why 2>/dev/null
echo "============================="

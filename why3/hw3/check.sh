#!/bin/sh

echo "====== ALT-EGRO SOLVER ======"
why3 prove -P alt-egro hw3.mlw 2>/dev/null
echo "======================="
echo "====== Z3 SOLVER ======"
echo "======================="
why3 prove -P z3 hw3.mlw 2>/dev/null
echo "=========================="
echo "====== Z3-CE SOLVER ======"
echo "=========================="
why3 prove -P z3-ce hw3.mlw 2>/dev/null
echo "============================"
echo "====== Z3-NOBV SOLVER ======"
echo "============================"
why3 prove -P z3-nobv hw3.mlw 2>/dev/null
echo "============================="

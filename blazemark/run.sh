set -e
./configure

# make dmatdmatmult
# ./bin/dmatdmatmult -no-classic

# make dmatdvecmult
# ./bin/dmatdvecmult -no-classic

make tdmatdvecmult
./bin/tdmatdvecmult -no-classic


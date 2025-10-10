# Compiler settings
CC = cc
MPI_CC = mpicc
CFLAGS = -O3

# Files
SERIAL_SRC = cpi.c getTime.c
MPI_SRC    = cpi_mpi.c getTime.c

# Targets
all: cpi cpi_mpi

# Serial version
cpi: $(SERIAL_SRC)
	$(CC) $(CFLAGS) -o cpi $(SERIAL_SRC)

# MPI version
cpi_mpi: $(MPI_SRC)
	$(MPI_CC) $(CFLAGS) -o cpi_mpi $(MPI_SRC)

# Clean
clean:
	rm -f cpi cpi_mpi *.o


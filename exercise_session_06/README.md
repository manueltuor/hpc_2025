## Sheet 6

### Exercise 1

• What happens when you run the code? Why?
  The program deadlocks. MPI_Ssend is blocking: it waits until the matching receive starts. 
  Since all processes try to send first, none of them reaches the receive call.
  
• Run the code again. What changed and why did it solve the problem? Is it an optimal solution?
  Since even ranks send and then receive and odd ranks receive and then send this guarantees that for every send
  a matching receive is ready, so no deadlock occurs. It is still not fully optimal since the communication is serialized.

• Why are these methods better solutions than synchronous communication for our ring problem?
	Using MPI_Isend / MPI_Irecv with MPI_Waitall allows non-blocking communication.

• Describe what advantage the new communicator provides.
  MPI_Cart_shift gives left/right ranks without manual modulo arithmetic, thus computing neighbours automatically. Also the Periodic boundaries (periods[0]=1) automatically handle the wrap-around.

### Exercise 2

• Approximated value of pi using 1000000000 terms: 3.141592652082950

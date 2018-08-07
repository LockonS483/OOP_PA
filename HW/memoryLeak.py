

def stackChain(i):
    i += 1;
    print("Iterations: " + str(i));
    stackChain(i);

stackChain(0);
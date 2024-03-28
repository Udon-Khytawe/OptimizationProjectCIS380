import random

# input a seed value so results can be recreated 
seed = int(input())
max_k = int(input())
random.seed(seed)

# get a random number of test cases
T = random.randint(1, 10)
print(T)

# for each test case
for i in range(T):
    # choose the number of integers
    N = random.randint(1, 2000)
    # choose the goal
    K = random.randint(1, max_k)
    print(N, K)
    print(*[random.randint(1, max_k) for i in range(N)])
print(seed)

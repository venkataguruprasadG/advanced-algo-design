n = int(input()) # this variable is about the number of paranthesis to be taken.

user_array = []
i = 0
while i < n:
    input_paranthesis = input()
    user_array.append(input_paranthesis) # here we are taking ipnut and appending it to an array.
    i += 1 # here we are updating the i so that we will take correctly the input number of paranthesis.

result = []
for j in user_array:
    target_string = j

    depth = 0

    for k, char in enumerate(target_string):
        if char == '(':
            depth += 1
        elif char == ')':
            depth -= 1

    if depth == 0:
        result.append("YES")
    else:
        result.append("NO")

for res in result:
    print(res)

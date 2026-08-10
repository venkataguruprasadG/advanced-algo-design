def paranthesis_generation(n, open_count=0, close_count = 0, current_string = '', solution = []):
    if open_count == n and close_count == n:
        solution.append(current_string)
    
    if open_count < n:
        paranthesis_generation(n, open_count + 1, close_count, current_string + '(', solution)
    
    if close_count < open_count:
        paranthesis_generation(n, open_count, close_count + 1, current_string + ')', solution)
    
    return solution


n = int(input())
result = paranthesis_generation(n)
print(result)
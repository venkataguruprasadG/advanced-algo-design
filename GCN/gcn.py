a = [
    [0,1,0],
    [1,0,0],
    [0,1,0]
]

b = [10,20,30]

a_tilde = [
    [1,1,0],
    [1,1,1],
    [0,1,1]
]

new_x = []

for person in range(3):
    total_score = 0
    connection_count = 0

    for friend in range(3):
        if a_tilde[person][friend] == 1:
            total_score += b[friend]
            connection_count += 1

    average_score = total_score / connection_count
    new_x.append(average_score)
print(new_x)

def solution(nums):
    answer = 0
    max = nums.pop()
    answer += 1
    while nums:
        i = nums.pop()
        if i > max:
            answer +=1
            max = i
    return answer

n = int(input())
nums = []
for i in range(n):
    nums.append(int(input()))
print(solution(nums))
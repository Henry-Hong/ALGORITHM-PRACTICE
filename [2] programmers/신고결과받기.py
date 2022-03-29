id_list = ["muzi", "frodo", "apeach", "neo"]
report = ["muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"]
k = 2

def solution(id_list, report, k):
    dict = { key: [] for key in id_list }
    cnt = { key: 0 for key in id_list}
    answer = [0] * len(id_list)

    for e in set(report):
        a, b = e.split(" ");
        dict[a].append(b)
        cnt[b] += 1
    
    i = 0
    for key, value in dict.items():
        for e in value:
            if cnt[e] >= k:
                answer[i] += 1
        i += 1

    return answer;

print(solution(id_list, report, k))
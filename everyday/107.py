from bisect import bisect_right

def avoidFlood(rains):
    n = len(rains)
    ans = [-1] * n  # 初始化答案数组
    lake_last_rain = dict()  # 记录每个湖上次下雨的下标
    zero_days = []  # 存放晴天的下标（可用于排干湖）
    
    for i, lake in enumerate(rains):
        if lake == 0:
            # 晴天，先标记索引
            zero_days.append(i)
            # 暂时填 1，后面可能会更新成干的湖号
            ans[i] = 1
        else:
            # 下雨天
            if lake in lake_last_rain:
                # 这个湖之前下过雨，必须在它再次下雨前排干
                # 找到晴天中第一个下标大于上次下雨的晴天
                idx = bisect_right(zero_days, lake_last_rain[lake])
                if idx == len(zero_days):
                    # 没有合适的晴天来排干 → 洪水
                    return []
                # 在这个晴天排干当前湖
                ans[zero_days[idx]] = lake
                # 删除使用过的晴天
                zero_days.pop(idx)
            # 更新湖的上次下雨下标
            lake_last_rain[lake] = i
            ans[i] = -1
    return ans

# 测试示例
print(avoidFlood([1,2,3,4]))       # [-1, -1, -1, -1]
print(avoidFlood([1,2,0,0,2,1]))   # [-1, -1, 2, 1, -1, -1] 或 [-1, -1, 1, 2, -1, -1]
print(avoidFlood([1,2,0,1,2]))     # []


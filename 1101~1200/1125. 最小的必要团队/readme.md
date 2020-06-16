# 1125. 最小的必要团队

```c++
作为项目经理，你规划了一份需求的技能清单 req_skills，并打算从备选人员名单 people 中选出些人组成一个「必要团队」（ 编号为 i 的备选人员 people[i] 含有一份该备选人员掌握的技能列表）。

所谓「必要团队」，就是在这个团队中，对于所需求的技能列表 req_skills 中列出的每项技能，团队中至少有一名成员已经掌握。

我们可以用每个人的编号来表示团队中的成员：例如，团队 team = [0, 1, 3] 表示掌握技能分别为 people[0]，people[1]，和 people[3] 的备选人员。

请你返回 任一 规模最小的必要团队，团队成员用人员编号表示。你可以按任意顺序返回答案，本题保证答案存在。

 

示例 1：

输入：req_skills = ["java","nodejs","reactjs"], people = [["java"],["nodejs"],["nodejs","reactjs"]]
输出：[0,2]
示例 2：

输入：req_skills = ["algorithms","math","java","reactjs","csharp","aws"], people = [["algorithms","math","java"],["algorithms","math","reactjs"],["java","csharp","aws"],["reactjs","csharp"],["csharp","math"],["aws","java"]]
输出：[1,2]
 

提示：

1 <= req_skills.length <= 16
1 <= people.length <= 60
1 <= people[i].length, req_skills[i].length, people[i][j].length <= 16
req_skills 和 people[i] 中的元素分别各不相同
req_skills[i][j], people[i][j][k] 都由小写英文字母组成
本题保证「必要团队」一定存在

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/smallest-sufficient-team
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

其实是一个二维背包问题，注意判断每一个维度的长度，将长度较小的那一个维度作为指数遍历的维度。

```c++
class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {

        int len = req_skills.size(); //任务数量
        int mxSize = 1 << len;
        vector<int> dp(mxSize, -1); //该位上有任务的最少人数
        unordered_map<int, vector<int>> team; // 为了执行int任务，用到哪些人
        unordered_map<int, int> mmp;
        unordered_map<string, int> skills;
        for (int i = 0; i < len; ++i) {
            skills[req_skills[i]] = i;
        }
        vector<vector<int>> peop;
        int dx = 0;
        for (int i = 0; i < people.size(); i++) {
            auto& t = people[i];
            if (t.size() == 0) continue;
            vector<int> vc;
            for (string& s : t) {
                int sid = skills[s];
                vc.push_back(sid);
            }
            bool flag = 1;
            for (auto& v : peop) {
                if (vc == v) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                mmp[dx] = i;
                dx++;
                peop.push_back(vc);
            }
        }


        dp[0] = 0;
        team[0] = vector<int>();

        //加进去第一个人
        for (int i = 0; i < peop.size(); i++) {
            int idx = 0;
            vector<int>& t = peop[i];
            for (int id : t) {
                if (id < len) {  //是我们需要的技能
                    idx = idx | (1 << id);
                }
            }
            for (int j = 0; j < mxSize; j++) {
                if (dp[j] >= 0) { //该点已经是可达状态，在该点的基础上将下一跳的状态变小。
                    int x = j | idx; //可以完成的任务
                    if (dp[x] == -1 || dp[x] > dp[j] + 1) {
                        dp[x] = dp[j] + 1;
                        team[x] = team[j];
                        team[x].push_back(mmp[i]);
                    }
                }
            }
        }

        return team[mxSize - 1];
    }
};
```

---


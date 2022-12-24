# 容斥原理
- ## 错位排列
  - <img src="https://s1.328888.xyz/2022/08/03/OpCU6.png" alt="image-20220724104219643" style="zoom:33%;" />
  - ![image-20220724103639345](https://s1.328888.xyz/2022/08/03/Op1TI.png)

- ## 不定方程非负数整数解个数

  ![image-20220724105346096](https://s1.328888.xyz/2022/08/03/Op9pr.png)

# 区间最大连续和

```cpp
class segtree {
public:
    struct node {
        int lsum = 0;
        int rsum = 0;
        int sum = 0;
        int realsum = 0;
        void apply(int l, int r, int v) {
            realsum = lsum = rsum = sum = v;
        }
    };
    node unite(const node& a, const node& b) const {
        node res;
        res.realsum = a.realsum + b.realsum;
            res.lsum = max(a.lsum, a.realsum + b.lsum);
            res.rsum = max(b.rsum, a.rsum + b.realsum);
        res.sum = max({res.lsum, res.rsum, b.lsum + a.rsum, a.sum, b.sum});
        return res;
    }
};
```


# 卡特兰数

![image-20220731133953365](C:\Users\14147\AppData\Roaming\Typora\typora-user-images\image-20220731133953365.png)

# 几何



# 字符串

### 前缀数组和KMP

```cpp
struct KMP
{
    string s;
    vector<int> kmp;
    void prefix_function()
    {
        int n = (int)s.length();
        kmp.resize(n);
        for (int i = 1; i < n; i++)
        {
            int j = kmp[i - 1];
            while (j > 0 && s[i] != s[j])
                j = kmp[j - 1];
            if (s[i] == s[j])
                j++;
            kmp[i] = j;
        }
    }

    vector<int> match(string &str)
    {   
        // debug(kmp);
        vector<int> ret;
        int patlen = this->s.length();
        int matchlen = str.length(), j = 0;

        for (int i = 0; i < matchlen; ++i)
        {
            while (j && this->s[j] != str[i])
            {
                j = kmp[j - 1];
            } 
            if (this->s[j] == str[i])
                ++j;
            if (j == patlen)
            {
                ret.push_back(i -  patlen + 1);
                j = kmp[j-1];
            }
        }
        return ret;
    }

    KMP(string &str)
    {
        s = str;
        prefix_function();
    }
};
/**string pat , match;
  *cin >> match >> pat; // match 匹配串 pat 模式串
  *KMP p(pat);// 按照模式串建立前缀数组
  *for(auto x:p.match(match)) cout << x + 1 << "\n";
  *for(auto x:p.kmp) cout << x << " ";
**/
```
### 循环字符串

```cpp
 period = len - kmp[len-1];
```

### 统计每个前缀出现的次数

```cpp
// C++ Version
vector<int> ans(n + 1);
for (int i = 0; i < n; i++) ans[pi[i]]++;
for (int i = n - 1; i > 0; i--) ans[pi[i - 1]] += ans[i];
for (int i = 0; i <= n; i++) ans[i]++;
```



# 数据结构




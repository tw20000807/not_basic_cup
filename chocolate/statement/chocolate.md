# 巧克力戰爭 (chocolate) 
本題為`Two Step`題，須上傳兩個檔案，限用 C++ 上傳。

## 題目描述
----
Ame 來到社部後後發現桌子上有 $b$ 個黑巧克力及 $n - b$ 個白巧克力，他知道這黑巧克力一定是 Char 要送給他女朋友一人一顆的，所以桌上有幾個黑巧克力就代表 Char 有幾個女朋友，而白巧克力則是 Char 自己要吃的。

 Ame 想讓 Bla 來社部時也能知道 Char 外面有多少女朋友，又想把這些巧克力都吃掉，於是 Ame 決定只留下其中的一些巧克力，並把他們排成一列，讓 Bla 回來後看到排成一列的巧克力後就能知道 Char 買了多少黑巧克力了。
 
 Ame 想吃越多巧克力，所以 **留下來的巧克力越少越好**。Ame 知道 Bla 可以根據一些線索得出原先總共有多少巧克力，也就是說， Bla 可以知道 $n$ 是多少，請你分別實作出 Ame 及 Bla 的策略。

## 實作細節
----
你必須上傳兩個檔案。

第一個檔案為 Ame.cpp  
在第一個檔案中你必須用以下的函式實作出 Ame 的策略
```cpp
std::string Ame(int n, int b);
```

* 代表 Ame 一開始看到桌上有 $b$ 個黑巧克力，$n - b$ 個白巧克力。
* 此函式須回傳一個由 'B' 和 'W' 構成的字串 (可以為空字串)，其中 'B' 的數量不能超過 $b$， 'W' 的數量不能超過 $n - b$

第二個檔案為 Bla.cpp  
在第二個檔案中你必須實作以下函式
```cpp
int Bla(int n, std::string s);
```
* $s$ 是從第一個檔案得到的字串。
* $n$ 代表一開始桌上總共有 $n$ 個巧克力，和第一個檔案傳入的 $n$ 是一樣的。
* 此函式必須回傳第一個檔案的 $b$ 是多少。

請注意，同一筆測資中可能會呼叫函式多次(最多呼叫 500 次)。

<div style="page-break-after: always"></div>

## 限制
----
* $1 \le b \le n < 1024$


## 子任務
----
1. (30 分) $n < 32$
2. (30 分) $n < 512$
3. (40 分) 無額外限制

## 評分方式
----
假設在同一個子任務的所有測資裡，最大的 $n$ 為 $N$，而你回傳的最長的字串長度為 $L$，則定義 $Q$ 為：
$$
Q = \max(0, L - \lceil \log_2 N \rceil )
$$

若你正確回答了同一個子任務的所有測資，根據 $Q$ ，你將得到分數比重 $W$：
$$
W =
\begin{cases}
1 & \text{if} &Q = 0 \\\\
0.5  &\text{if} &1 \le Q \le 10 \\\\
0 &\text{if} &Q > 10
\end{cases}
$$

你在該子任務的得分為 $W$ 乘以該子任務的總分。

<div style="page-break-after: always"></div>

## 範例 
----
### 範例 1
judge 呼叫
```
Ame(10, 5)
```
回傳
```
"BBBBB"
```
judge 呼叫
```
Bla(10, "BBBBB")
```
回傳
```
5
```

## 範例評分程式
----
範例評分程式採用以下格式輸入：

>$T$  
>$n_1$  $b_1$  
>$n_2$  $b_2$  
>$...$  
>$n_T$  $b_T$


代表說會呼叫 $T$ 次函式，第 $i$ 次的輸入為 $n_i$  $b_i$

對於每次呼叫，範例評分程式第一行會輸出你是否答對  
第二行會輸出 Ame 回傳的字串  
第三行會輸出 Bla 回傳的數字

## @{keyword.statement}

@{lang.ja}

算数の時間に xor という演算を習ったデグくんは、yor や zor という演算はないのかと気になりました。しかし、誰に聞いてもそんな演算はないの一点張りです。悔しくなったデグくんは自分で zor をつくることにしました。

zor とは非負整数に対して定義される二項演算で、非負整数から非負整数への全単射写像 $P$ によって以下のように定まります。

- $x,y$ を非負整数、$\displaystyle x=\sum_{n=0}^{\infty}x_n2^n,\ y=\sum_{n=0}^{\infty}y_n2^n\ (x_n,y_n\in \\{0,1\\})$ をその2進数表示とします。このとき $x$ と $y$ の zor は
$$x\ \mathrm{zor}\ y=\sum_{n=0}^{\infty} ((x_n+y_{P(n)})\bmod 2)2^n$$
と表される非負整数です。

この演算 zor の性質を調べるためにデグくんはいくつかのテストをすることにしました。非負整数の集合 $A=\\{A_1,\ldots,A_N\\}$ が与えられます。集合 $S_n\ (n=0,1,2,\ldots)$ を以下のように定めます。

- $S_0=A$
- $n>0$ なら $S_n=S_{n-1}\cup \\{x\ \mathrm{zor}\ y\mid x,y\in S_{n-1}\\}$

$\displaystyle S=\bigcup_{n=0}^{\infty}S_n$ としたとき、$S$ の要素数 $|S|$ を $@{param.mod}$ で割ったあまりを求めてください。ただしこの問題の制約のもと $|S|$ は有限であることが証明できます。

@{lang.end}

## @{keyword.constraints}

- $@{param.MIN_N} \leq N \leq @{param.MAX_N}$
- $@{param.MIN_K} \leq K \leq @{param.MAX_K}$
- $0\leq A_i\lt 2^{K}$
- 非負整数 $n$ が $K$ より小さいなら $P(n)<K$
- 非負整数 $n$ が $K$ 以上なら $P(n)=n$
- 非負整数 $n,m$ に対して $n\neq m$ なら $P(n)\neq P(m)$

## @{keyword.input}

入力は以下の形式で与えられる。

```
$N$ $K$
$P(0)$ $P(1)$ $\ldots$ $P(K-1)$
$A_1$
$\vdots$
$A_N$
```

非負整数 $n$ が $K$ 以上なら $P(n)=n$ である。$n\ge K$ なら $P(n)$ は入力では与えられないことに注意せよ。また、各 $A_i$ はそれぞれ2進数表示で $K$ 桁、$2^{K -1}$ の位から $2^0$ の位までが位の指数の降順で与えられる。

## @{keyword.output}
$|S|$ を $@{param.mod}$ で割ったあまりを一行に出力する。

## @{keyword.sample}

@{example.example_00}

例えば $A_1\ \mathrm{zor}\ A_1=1111$ です。

@{example.example_01}

@{example.example_02}

$@{param.mod}$ で割ったあまりを出力してください。

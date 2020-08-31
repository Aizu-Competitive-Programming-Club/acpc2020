## @{keyword.statement}

@{lang.ja}

算数の時間にxorという演算を習ったデグくんは、yorやzorという演算はないのかと気になりました。しかし、誰に聞いてもそんな演算はないの一点張りです。悔しくなったデグくんは自分でzorをつくることにしました。

zorとは非負整数に対して定義される二項演算で、非負整数から非負整数への全単射写像$P$によって以下のように定まります。

- $x,y$を非負整数、$\displaystyle x=\sum_{n=0}^{\infty}x_n2^n,\ y=\sum_{n=0}^{\infty}y_n2^n\ x_n,y_n\in \{0,1\}$をその二進数表示とします。このとき$x$と$y$のzorは
$$x\ \mathrm{zor}\ y=\sum_{n=0}^{\infty} ((x_n+y_{P(n)})\bmod 2)2^n$$
と表される非負整数です。

この演算zorの性質を調べるためにデグくんはいくつかのテストをすることにしました。非負整数の集合$A=\{A_1,\ldots,A_N\}$が与えられます。集合$S_n\ (n=0,1,2,\ldots)$を以下のように定めます.

- $S_0=A$
- $n>0$なら$S_n=S_{n-1}\cup \\{x \mathrm{zor} y\mid x,y\in S_{n-1}\\}$

$\displaystyle S=\bigcup_{n=0}^{\infty}S_n$としたとき、$S$の要素数$|S|$を$998244353$で割ったあまりを求めてください。ただしこの問題の制約のもと$|S|$は有限であることが証明できます。

@{lang.end}

## @{keyword.constraints}

- $@{param.MIN_N} \leq N \leq @{param.MAX_N}$
- $0\leq A_i\lt 2^{@{param.K}}$
- 非負整数$n$が$@{param.K}$より小さいなら$P(n)<@{param.K}$
- 非負整数$n$が$@{param.K}$以上なら$P(n)=n$

## @{keyword.input}
各$A_i$はそれぞれ2進数表示で$@{param.K}$桁、$2^{@{param.K} -1}$の位から$2^0$の位までがこの順番で与えられる。

```
$N$
$P_0$ $P_1$ $\ldots$ $P_{@{param.K} -1}$
$A_1$
$\vdots$
$A_N$
```

## @{keyword.output}
$|S|$を一行に出力する。

## @{keyword.sample}

@{example.example_00}

@{example.example_01}

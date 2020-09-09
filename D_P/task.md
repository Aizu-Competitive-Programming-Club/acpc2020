## @{keyword.statement}

@{lang.ja}

整数 $N$、 $P$  と長さ $N$ の整数列 $A={A_0,\ldots,A_{N-1}}$ があります。

以下の条件を満たす長さ $N$ の整数列 $B={B_0,\ldots,B_{N-1}}$ を構築してください。ここで $f(B)=\displaystyle\sum_{i=0}^{N-1} B_i$ と定めます。

- $f(B)$ は正の整数
- $A_i = {\large \left\lfloor\frac{B_i\times P}{f(B)}\right\rfloor}  \ (0 \le i \lt N)$ が成立する

条件を満たす整数列 $B$ が複数ある場合は $f(B)$ が最小のもの、それが等しいものが複数ある場合はその中で辞書順最小のものを出力してください。

この制約下では整数列 $B$ を必ず構築することができます。

ただし、長さ $N$ の整数列 $C={C_0,\ldots,C_{N-1}}$、 $D={D_0,\ldots,D_{N-1}}$ に対して辞書順で $C$ が $D$ より小さいとは $C_j = D_j$、 $C_i \lt D_i\ (j \lt i)$ が成立する整数 $i$ が存在することを言います。

実数 $x$ に対して $\lfloor x \rfloor$ とは $x$ 以下の最大の整数を表します。

@{lang.end}
## @{keyword.constraints}

- $@{param.N_MIN} \le N \le @{param.N_MAX}$
- $@{param.P_MIN} \leq P \leq @{param.P_MAX}$
- $@{param.A_MIN} \le A_i \le P$
- $ P - N + 1\leq\displaystyle\sum_{i=0}^{N-1} A_i \leq P$
- 入力はすべて整数である

## @{keyword.input}

入力は以下の形式で与えられる。

```
$N$ $P$
$A_0$ $A_1$ $\cdots$ $A_{N-1}$
```

## @{keyword.output}

以下の形式で答えを出力せよ。

```
$B_0$ $B_1$ $\cdots$ $B_{N-1}$
```

## @{keyword.sample}

@{example.example_00}

$\left\lfloor\frac{26\times 100}{51}\right\rfloor$ は $50$、 $\left\lfloor\frac{25\times 100}{51}\right\rfloor$ は $49$となる。

@{example.example_01}

@{example.example_02}

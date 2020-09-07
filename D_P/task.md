## @{keyword.statement}

@{lang.ja}

整数 $N$, $P$  と長さ $N$ の数列 $A$ があります。ここで数列 $A$ の各要素を整数 $i$ を用いて $A_i \ (0 \le i \lt N)$ と表します。

以下の条件を満たす長さ $N$ の数列 $B$ を構築してください。

- 数列 $B$ の各要素は整数
- $\sum_{i=0}^{n-1} B_i$ は正の整数
- $A_i = {\large\left\lfloor\frac{B_i\times P}{\sum_{i=0}^{n-1} B_i}\right\rfloor}$ が成立する

条件を満たす数列 $B$ が複数ある場合は $\sum_{i=0}^{n-1} B_i$ が最小のもの、それが等しいものが複数ある場合はその中で辞書順最小のものを出力してください。

ただし、長さ $N$ の数列 $C$, $D$ に対して辞書順で $C$ が $D$ より小さいとは $C_j = D_j\ (j \lt i)$ , $C_i \lt D_i$ が成立する整数 $i$ が存在することを言います。

実数 $x$ に対して $\lfloor x \rfloor$ とは $x$ 以下の最大の整数を表します。

@{lang.end}
## @{keyword.constraints}

- $@{param.N_MIN} \le N \le @{param.N_MAX}$
- $@{param.P_MIN} \leq P \leq @{param.P_MAX}$
- $@{param.A_MIN} \le A_i \le P$
- 条件を満たす数列 $B$ を構築できる
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

@{example.example_01}

@{example.example_02}

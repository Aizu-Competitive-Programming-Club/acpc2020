## @{keyword.statement}

@{lang.ja}

XY平面上に $1$ から $N$ までの番号が付けられた $N$ 本の直線があります。
$i (1 \le i \le N)$ 本目の直線は $y = A_ix + B_i$ で表されます。
次のクエリを $Q$ 回処理してください。

- $L_j$ 本目の直線から $R_j$ 本目までの直線が $x = P_j$ で取る $y$ 座標のうち、最小値を出力 $(1 \le j \le Q)$

@{lang.end}

## @{keyword.constraints}

- 入力は全て整数
- $@{param.N_MIN} \leq N \leq @{param.N_MAX}$
- $@{param.Q_MIN} \leq Q \leq @{param.Q_MAX}$
- $|A_i|, |B_i| \leq @{param.A_MAX} (1 \leq i \leq N)$
- $@{param.N_MIN} \leq L_j \leq R_j \leq N (1 \leq j \leq Q)$
- $|P_j| \leq @{param.X_MAX} (1 \leq j \leq Q)$

## @{keyword.input}

$1$ 行目に直線の本数 $N$ と、クエリの数 $Q$ が与えられます。

$2$ 行目から $N+1$ 行目にかけて、整数 $A_i, B_i$ が与えられます。

$N+2$ 行目から $N+Q+1$ 行目にかけて、整数 $L_j, R_j, P_j$ が与えられます。

```
$N$ $Q$
$A_1$ $B_1$
$\vdots$
$A_N$ $B_N$
$L_1$ $R_1$ $P_1$
$\vdots$
$L_Q$ $R_Q$ $P_Q$
```

## @{keyword.output}

クエリごとに、 $y$ 座標の最小値を $1$ 行に出力してください。

## @{keyword.sample}

@{example.example_00}

$1$ つめのクエリでは、直線 $y = 2x$ に $x = 5$ を代入して $y$ の最小値 $10$ を出力します。
$2$ つめのクエリでは、直線 $y = 2x$ と $y = -5x + 10$ に $x = 5$ を代入して $y$ の最小値 $-15$ を出力します。

@{example.example_01}

@{example.example_02}

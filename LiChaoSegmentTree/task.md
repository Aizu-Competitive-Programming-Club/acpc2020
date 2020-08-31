## @{keyword.statement}

@{lang.ja}

$N$本の直線$y = A_ix + B_i$が存在します。
次のクエリを$Q$回処理してください。

- $L_i$本目の直線から$R_i$本目までの直線が$x = P_i$で取る$y$座標のうち、最小値を出力

@{lang.end}

## @{keyword.constraints}

- 入力は全て整数
- $@{param.N_MIN} \leq N \leq @{param.N_MAX}$
- $@{param.Q_MIN} \leq Q \leq @{param.Q_MAX}$
- $A_i \leq |@{param.A_MAX}|$
- $B_i \leq |@{param.B_MAX}|$
- $P_i \leq |@{param.X_MAX}|$

## @{keyword.input}

$1$行目に直線の本数$N$と、クエリの数$Q$が与えられます。

$2$行目から$N+1$行目にかけて、直線を表す整数$A_i, B_i$が与えられます。

$N+2$行目から$N+Q+2$行目にかけて、整数$L_i, R_i, P_i$が与えられます。

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

クエリごとに、$y$座標の最小値を$1$行に出力してください。

## @{keyword.sample}

@{example.example_00}
@{example.example_01}

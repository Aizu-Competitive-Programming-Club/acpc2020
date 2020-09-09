## @{keyword.statement}

@{lang.ja}

$N$ 個の関数 $f_1, f_2, \ldots , f_N$ があります。$f_i(x) = A_ix + B_i$ です。

以下で説明されるクエリを順に $Q$ 回処理して下さい。

- $j$ 回目のクエリで整数 $L_j, R_j, P_j$ が与えられるので、$\displaystyle \min_{L_j \le i \le R_j}f_i(P_j)$ を出力する

@{lang.end}

## @{keyword.constraints}

- 入力は全て整数
- $@{param.N_MIN} \leq N \leq @{param.N_MAX}$
- $@{param.Q_MIN} \leq Q \leq @{param.Q_MAX}$
- $|A_i|, |B_i| \leq @{param.A_MAX}$
- $@{param.N_MIN} \leq L_j \leq R_j \leq N$
- $|P_j| \leq @{param.X_MAX}$

## @{keyword.input}

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

各クエリに対して答えを一行に出力して下さい。

## @{keyword.sample}

@{example.example_00}

この入力では $f_1(x) = 2x$ と $f_2(x) = -5x + 10$ の二つの関数が与えられます。

一つ目のクエリでは、$f_1$ のみが対象であるため、$f_1(5) = 10$ を出力します。

二つ目のクエリでは、両方の関数が対象です。$f_1(5) = 10, f_2(5) = -15$ のうち、最小である $-15$ を出力します。

@{example.example_01}

@{example.example_02}

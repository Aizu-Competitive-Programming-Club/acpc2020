## @{keyword.statement}

@{lang.ja}

$N$ 頂点からなる無向グラフ $G$ を考える。最初、$G$ に辺は存在しない。$G$ の辺集合を $E(G)$ と表す。

以下のクエリ $Q$ 個を処理せよ。

- `u v` : 辺 $\\{u, v\\}$ が存在すれば削除し、存在しなければ追加する
- その後、頂点 $w$ の次数を $d_w$ として $\displaystyle \sum_{\\{u, v\\} \in E(G)} d_a d_b$ を出力する

@{lang.end}

## @{keyword.constraints}
- $@{param.N_MIN} \leq N \leq @{param.N_MAX}$
- $@{param.Q_MIN} \leq Q \leq @{param.Q_MAX}$
- $1 \leq u_i \lt v_i \leq N$
- 入力は全て整数

## @{keyword.input}

```
$N$ $Q$
$u_1$ $v_1$
$\hspace{11pt} \vdots$
$u_Q$ $v_Q$
```

## @{keyword.output}

出力は $Q$ 行からなる。

$i$ 行目には $i$ 番目のクエリに対する答えを出力せよ。

## @{keyword.sample}

@{example.example_00}
$1$ つ目のクエリでは、辺 $\\{1, 2\\}$ を追加し、$d_1 d_2 = 1$ を出力する。

$2$ つ目のクエリでは、辺 $\\{2, 3\\}$ を追加し、$d_1 d_2 + d_2 d_3 = 1 \times 2 + 2 \times 1 = 4$ を出力する。

$3$ つ目のクエリでは、辺 $\\{3, 4\\}$ を追加し、$d_1 d_2 + d_2 d_3 + d_3 d_4 = 1 \times 2 + 2 \times 2 + 2 \times 1 = 8$ を出力する。

$4$ つ目のクエリでは、辺 $\\{2, 3\\}$ を削除し、$d_1 d_2 + d_3 d_4 = 1 \times 1 + 1 \times 1 = 2$ を出力する。

$5$ つ目のクエリでは、辺 $\\{2, 3\\}$ を追加し、$d_1 d_2 + d_2 d_3 + d_3 d_4 = 1 \times 2 + 2 \times 2 + 2 \times 1 = 8$ を出力する。

@{example.example_01}

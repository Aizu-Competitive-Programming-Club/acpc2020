## @{keyword.statement}

@{lang.ja}

$N$ 頂点のグラフ $G$ を考える。最初、$G$ に辺は存在しない。

以下のクエリ $Q$ 個を処理してください。

- `u v` : 辺 $(u, v)$ が存在すれば削除し、存在しなければ作成する。
- その後、頂点 $w$ の次数を $d_w$ として $\displaystyle \sum_{(a, b) \in E(G)} d_a d_b$ を出力。

@{lang.end}

## @{keyword.constraints}
- $@{param.N_MIN} \leq N \leq @{param.N_MAX}$
- $@{param.Q_MIN} \leq Q \leq @{param.Q_MAX}$
- $1 \leq u_i \lt v_i \leq N$

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

@{example.example_01}

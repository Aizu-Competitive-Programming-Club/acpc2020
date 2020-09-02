## @{keyword.statement}

@{lang.ja}

考古学者のtoyamaさんはある二次元の国に訪れた際に奇妙な地形を目にして気になりました。
調査をしたところ、この奇妙な地形は沢山の山が生まれて山々が干渉した結果出来たようです。
$N$ 個の山は次のように一直線上に生まれました。

それぞれの山は、底辺が $R_i$、高さ $H_i$ の二等辺三角形で座標 $X_i$ を中心として地面が盛り上がることによって生まれます。
もし、複数の山がある地点を盛り上げた際にはその地点の標高はそれぞれの山が盛り上げる高さの和になります。

考古学者のtoyamaさんはこの国で一番標高が高い場所の標高がどれくらいなのか気になりました。
プログラマーのあなたはそれを計算するプログラムを制作してください。

@{lang.end}

## @{keyword.constraints}

- $@{param.N_MIN} \leq N \leq @{param.N_MAX}$
- $@{param.X_MIN} \leq X_i \leq @{param.X_MAX}$
- $@{param.H_MIN} \leq H_i \leq @{param.H_MAX}$
- $@{param.R_MIN} \leq R_i \leq @{param.R_MAX}$
- 全ての入力は整数である。

## @{keyword.input}
$1$ 行目に山の個数 $N$ が与えられる。
続く、$N$ 行は $X_i H_i R_i$ が空白区切りで与えられる。

```
$N$
$X_1$ $H_1$ $R_1$
$\vdots$
$X_N$ $H_N$ $R_N$
```

## @{keyword.output}
一番標高が高い地点の高さを一行目に出力する。
尚、想定解から$10^{-6}$までの相対誤差は正答扱いとする。

## @{keyword.sample}
@{example.example_00}
@{example.example_01}
@{example.example_02}

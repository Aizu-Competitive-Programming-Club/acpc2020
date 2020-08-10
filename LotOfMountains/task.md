## @{keyword.statement}

@{lang.ja}

考古学者のtekiheiさんはある国に訪れましたが、奇妙な地形をしていて気になりました。
調査をしたところ、沢山の山が生まれてお互いが干渉しあって出来たようです。
N個の山は一直線上に生まれます。それぞれの山は、半径 $R_i$ 、高さ $H_i$ の円錐状に位置 $X_i$ を中心として地面が盛り上がることによって生まれるそうです。もし、ある地点で複数の山が被さるように生まれた場合、ある地点の標高はそれぞれの山の合算値となる。
考古学者のtekiheiさんはこの国で一番標高が高い場所の標高がどれくらいなのか気になりました。
プログラマーのあなたはそれを計算するプログラムを制作してください。

@{lang.end}

## @{keyword.constraints}

- $@{param.N_MIN} \leq N \leq @{param.N_MAX}$
- $@{param.X_MIN} \leq X_i \leq @{param.X_MAX}$
- $@{param.H_MIN} \leq H_i \leq @{param.H_MAX}$
- $@{param.R_MIN} \leq R_i \leq @{param.R_MAX}$


## @{keyword.input}
$1$ 行目に山の個数 $N$ が与えられる。
続く、$N$ 行は $X_i H_i R_i$ が空白区切りで与えられる。
尚、全ての入力は整数で与えられる。

```
$N$
$X_1 H_1 R_1$
$\vdots$
$X_N H_N R_N$
```

## @{keyword.output}
一番標高が高い地点の高さを位置業に出力する。
尚、想定解から1e-6までの相対誤差は正答扱いとする。

## @{keyword.sample}
@{example.example_00}
@{example.example_01}

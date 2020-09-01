## @{keyword.statement}

@{lang.ja}

$N$頂点からなる凸多角形で表される折り紙がある。
折り紙に対して操作をM回行う。

$i(1 \leq i \leq M)$回目の操作は以下のように表される。

- [このページの図](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_C&lang=ja)のように、直線$(p_i, q_i)$を折り目とし、折り紙の右側の領域を左側に折る。

$M$回の操作後、各$i = 1, 2, \cdots, 2^M$に対して、$i$枚の紙が重なっている領域の面積を求めよ。


@{lang.end}

## @{keyword.constraints}

- $@{param.N_MIN} \leq N \leq @{param.N_MAX}$
- $@{param.M_MIN} \leq M \leq @{param.M_MAX}$
- $@{param.xy_MIN} \leq x, y \leq @{param.xy_MAX}$

## @{keyword.input}


```
$N$ $M$
$x_1$ $y_1$
$x_2$ $y_2$
:
$x_N$ $y_N$
$p_1x$ $p_1y$ $q_1x$ $q_1y$
$p_2x$ $p_2y$ $q_2x$ $q_2y$
:
$p_Mx$ $p_My$ $q_Mx$ $q_My$
```
1行目の $N$と$M$ はそれぞれ凸多角形の点の数と操作の回数を表す。 
続く $N$ 行に点$i$の座標が２つの実数 $xi$ $yi$ で与えられる。点は、多角形の隣り合った点を反時計回りに訪問するような順番で与えられる。 
続く$M$行に直線iを構成する2つの点$pi, qi$が4つの実数$p_ix$ $p_iy$ $q_ix$ $q_iy$で与えられる。 
また、座標を表す実数は小数点以下最大６桁まで与えられる。

## @{keyword.output}
各$i = 1, 2, \cdots, 2^M$に対して、$i$枚の紙が重なっている領域の面積を求めよ。出力値は0.000001以下の誤差を許容する。

## @{keyword.sample}

@{example.example_00}

@{example.example_01}

@{example.example_02}

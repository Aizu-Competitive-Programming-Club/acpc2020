## @{keyword.statement}

@{lang.ja}

xy平面上に$N$ 頂点からなる凸多角形で表される折り紙がある。
折り紙に対して操作を $M$ 回行う。

$i\ (1 \leq i \leq M)$ 回目の操作は以下のように表される。

- [このページの図](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_C&lang=ja)のように、2点$p_i$, $q_i$ を通る直線を折り目とし、折り紙の右側部分を左側に折る。

$M$ 回の操作後、各 $i = 1, 2, 3, \dots, 2^M$ に対して、$i$ 枚の紙が重なっている部分の面積を求めよ。


@{lang.end}

## @{keyword.constraints}

- $@{param.N_MIN} \leq N \leq @{param.N_MAX}$
- $@{param.M_MIN} \leq M \leq @{param.M_MAX}$
- $@{param.xy_MIN} \leq x_i, y_i \leq @{param.xy_MAX}$
- $@{param.xy_MIN} \leq a_i, b_i, c_i, d_i \leq @{param.xy_MAX}$
- 点 $p_i$ と点 $q_i$ は異なる
- 与えられる直線 $p_i$ $q_i$ は必ず折り紙に交差する

## @{keyword.input}


```
$N$ $M$
$x_1$ $y_1$
$x_2$ $y_2$
$\vdots$
$x_N$ $y_N$
$a_1$ $b_1$ $c_1$ $d_1$
$a_2$ $b_2$ $c_2$ $d_2$
$\vdots$
$a_M$ $b_M$ $c_M$ $d_M$
```
1行目の $N$ と $M$ はそれぞれ凸多角形の点の数と操作の回数を表す。 
続く $N$ 行に凸多角形の$i$番目の点の座標が2つの実数 $x_i$ $y_i$ で与えられる。点は、多角形の隣り合った点を反時計回りに訪問するような順番で与えられる。 
続く$M$行に 2点$p_i$, $q_i$ を通る直線を表す4つの実数 $a_i$ $b_i$ $c_i$ $d_i$ が与えられる。点 $p_i$ の座標は $(a_i$, $b_i)$ 、点 $q_i$ の座標は $(c_i$, $d_i)$ で表される。 
また、座標を表す実数は小数点以下最大 $@{param.significant_digit}$ 桁まで与えられる。

## @{keyword.output}
$2^M$ 行出力する。 $i$ 行目には $i$ 枚の紙が重なっている部分の面積を出力せよ。また出力値の絶対誤差または相対誤差が $10^{-@{param.significant_digit}}$ 以下の場合、正答と判定される。

## @{keyword.sample}

@{example.example_00}
1枚の紙が重なる部分の面積が3、2枚の紙が重なる部分の面積が0.5になります。

@{example.example_01}

@{example.example_02}

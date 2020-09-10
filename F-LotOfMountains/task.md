## @{keyword.statement}

@{lang.ja}

それぞれ $N$ 個の整数 $X_1, X_2, ..., X_N$, $H_1, H_2, ..., H_N$, $R_1, R_2, ..., R_N$ が与えられ、関数 $f(x)$ を次のように定義します。

$f(x) = \displaystyle \sum_{i=1}^{N} \max(0, H_i (1 - \displaystyle \frac{2|x - X_i|}{R_i}))$

$\displaystyle \max_{-\infty \leq x \leq \infty}f(x)$ を計算してください。

@{lang.end}

## @{keyword.constraints}

- $@{param.N_MIN} \leq N \leq @{param.N_MAX}$
- $@{param.X_MIN} \leq X_i \leq @{param.X_MAX}$
- $@{param.H_MIN} \leq H_i \leq @{param.H_MAX}$
- $@{param.R_MIN} \leq R_i \leq @{param.R_MAX}$
- 全ての入力は整数である

## @{keyword.input}
1行目に山の個数 $N$ が与えられる。
続く $N$ 行は $X_i,H_i,R_i$ が空白区切りで与えられる。

```
$N$
$X_1$ $H_1$ $R_1$
$\vdots$
$X_N$ $H_N$ $R_N$
```

## @{keyword.output}
一番標高が高い地点の高さを一行目に出力する。
なお、想定解から$10^{-@{param.EPS_DIGIT}}$までの相対誤差は正答扱いとする。

## @{keyword.sample}
@{example.example_00}
x座標の小さい順から山の標高は次のようになります。  
座標 $x=8$ で標高 $0$  
座標 $x=9$ で標高 $2$  
座標 $x=10$ で標高 $6$  
座標 $x=11$ で標高 $2$  
座標 $x=12$ で標高 $0$  
@{example.example_01}
@{example.example_02}

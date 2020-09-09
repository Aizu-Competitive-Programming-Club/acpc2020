## @{keyword.statement}

@{lang.ja}
$X_i, H_i, R_i \(1 \leq i \leq N\)$ が与えられ、実数 $x$ を受け取る関数 $f(x)$ を次のように定義します。

$f(x) = \displaystyle \sum_{i=1}^{N} \max \left( 0, H_i \left(1 - \displaystyle \frac{2|x - X_i|}{R_i}\right) \right)$

$f(x)$ の最大を計算してください。

@{lang.end}

## @{keyword.constraints}

- $@{param.N_MIN} \leq N \leq @{param.N_MAX}$
- $@{param.X_MIN} \leq X_i \leq @{param.X_MAX}$
- $@{param.H_MIN} \leq H_i \leq @{param.H_MAX}$
- $@{param.R_MIN} \leq R_i \leq @{param.R_MAX}$
- 全ての入力は整数である

## @{keyword.input}
1行目に $N$ が与えられる。
続く $N$ 行は $X_i,H_i,R_i$ が空白区切りで与えられる。

```
$N$
$X_1$ $H_1$ $R_1$
$\vdots$
$X_N$ $H_N$ $R_N$
```

## @{keyword.output}

$f(x)$ の最大を1行目に出力してください。
なお、想定解から$10^{-@{param.EPS_DIGIT}}$までの相対誤差は正答扱いとします。

## @{keyword.sample}
@{example.example_00}
x座標の小さい順から山の標高は次のようになります。  
座標 $x=8$ で標高 $0$  
座標 $x=9$ で標高 $2$  
座標 $x=10$ で標高 $6$  
座標 $x=11$ で標高 $2$  
座標 $x=12$ で標高 $0$  

また、この入力に対する解答として $6$ や $6.0$ なども有効です。
@{example.example_01}
@{example.example_02}

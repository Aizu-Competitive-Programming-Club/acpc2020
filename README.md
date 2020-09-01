# acpc2020

### Pros
- 制約を一元管理
- サンプルの自動挿入
- CI

### Cons
- C++ だけ


### 準備
```
pip install -r requirements.txt
```

### 原案
issue に原案を書く（driveではなく） issue template を使ってください　~"Labels" から "Problem" のラベルをつけておく~ 

数式は[これ](https://gist.github.com/a-rodin/fef3f543412d6e1ec5b6cf55bf197d7b#file-a-hack-for-showing-latex-formulas-in-github-markdown-md) を参考に

~[問題の様子](https://docs.google.com/spreadsheets/d/1wsrpUeR21S00EFWw1Z-HYIfQm0EckRZMM6kEBML0zBg/) に動線を貼る。~

採用後、task.mdを書いたらissueの本文を削除する（毎年混乱の元なので）

例：https://github.com/Aizu-Competitive-Programming-Club/acpc2020/issues/1


### 問題作成
```
cp -r SpecialChat $Problem
cd $Problem
./test.sh
```

### Push
```
./test.sh
```
をして、エラーが出ないことを確認してからPushすること

CIを実行したい場合は、コミットメッセージに\[run ci\]を含める。
例：
```
git commit -m '[run ci] add SpecialChat'
```

### いじるとこ
| 対象 | 場所 |
| --- | --- |
| rimeのTESTSET | info.toml |
| 共通の制約 | info.toml |
| 問題文 | task.md |
| 想定解 | sol/correct.cpp |
| generator | gen |
| validator | verifier.cpp |
| checker | checker.cpp |
<!-- start * -->
<!-- start LiChaoSegmentTree-->
## LiChaoSegmentTree
### Time Limit: 2.0
| solution name | type |
|----|----|
|wa.cpp|WA|
<!-- end LiChaoSegmentTree -->

<!-- start Monochrome Stone-->
## Monochrome Stone
### Time Limit: 2.0
| solution name | type |
|----|----|
|wa.cpp|WA|
<!-- end Monochrome Stone -->

<!-- start RTA-->
## RTA
### Time Limit: 2.0
| solution name | type |
|----|----|
|wa.cpp|WA|
|beet.cpp|AC|
|shot.cpp|AC|
|keymoon.cpp|AC|
|Endered.cpp|AC|
|ok.cpp|AC|
<!-- end RTA -->

<!-- start LotOfMountains-->
## LotOfMountains
### Time Limit: 2.0
| solution name | type |
|----|----|
|wa-1e-5.cpp|WA|
|rel-1e-7.cpp|AC|
<!-- end LotOfMountains -->

<!-- start SpecialChat-->
## SpecialChat
### Time Limit: 2.0
| solution name | type |
|----|----|
|wa.cpp|WA|
<!-- end SpecialChat -->

<!-- start DEG MUL SUM-->
## DEG MUL SUM
### Time Limit: 2.0
| solution name | type |
|----|----|
|wa.cpp|WA|
<!-- end DEG MUL SUM -->

<!-- start zor-->
## zor
### Time Limit: 2.0
| solution name | type |
|----|----|
|wa.cpp|AC|
|tubuann.cpp|AC|
<!-- end zor -->

<!-- start Islands-->
## Islands
### Time Limit: 8.0
| solution name | type |
|----|----|
|bf.cpp|WA|
<!-- end Islands -->

<!-- start A + B-->
## A + B
### Time Limit: 2.0
| solution name | type |
|----|----|
|wa.cpp|WA|
<!-- end A + B -->

<!-- end * -->

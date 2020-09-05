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
をして、エラーが出ないことを確認してからpushすること

info.toml の titleを適切に編集すること

masterでCIを実行したい場合は、コミットメッセージに\[run ci\]を含める。
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
<!-- start A - RTA -->
## A - RTA
### Time Limit: 2.0
| solution name | type |
|----|----|
|wa.cpp|WA|
|beet.cpp|AC|
|shot.cpp|AC|
|keymoon.cpp|AC|
|Endered.cpp|AC|
|ok.cpp|AC|
###### updated 2020/09/05 20:56:43
<!-- end A - RTA -->

<!-- start B - LiChaoSegmentTree -->
## B - LiChaoSegmentTree
### Time Limit: 2.0
| solution name | type |
|----|----|
|wa.cpp|WA|
|Endered.cpp|AC|
|Luzhiled.cpp|AC|
|shot.cpp|AC|
|keymoon.cpp|AC|
###### updated 2020/09/05 20:56:43
<!-- end B - LiChaoSegmentTree -->

<!-- start C - Broken Machine -->
## C - Broken Machine
### Time Limit: 2.0
| solution name | type |
|----|----|
|self_loop.cpp|WA|
|extra_out.cpp|WA|
|Endered.cpp|AC|
###### updated 2020/09/05 20:56:43
<!-- end C - Broken Machine -->

<!-- start D - P -->
## D - P
### Time Limit: 2.0
| solution name | type |
|----|----|
|wa.cpp|WA|
|correct2.cpp|AC|
|Endered.cpp|AC|
|keymoon.cpp|AC|
###### updated 2020/09/05 20:56:43
<!-- end D - P -->

<!-- start E - Monochrome Stone -->
## E - Monochrome Stone
### Time Limit: 2.0
| solution name | type |
|----|----|
|wa.cpp|WA|
|Endered.cpp|AC|
|toyama.cpp|AC|
|Luzhiled.cpp|AC|
###### updated 2020/09/05 20:56:43
<!-- end E - Monochrome Stone -->

<!-- start F - LotOfMountains -->
## F - LotOfMountains
### Time Limit: 2.0
| solution name | type |
|----|----|
|wa-1e-5.cpp|WA|
|tle.cpp|TLE|
|heuristic.cpp|WA|
|rel-1e-7.cpp|AC|
|Luzhiled.cpp|AC|
|keymoon.cpp|AC|
###### updated 2020/09/05 20:56:43
<!-- end F - LotOfMountains -->

<!-- start G - Connect the dots -->
## G - Connect the dots
### Time Limit: 2.0
| solution name | type |
|----|----|
|wa.cpp|WA|
###### updated 2020/09/05 20:56:43
<!-- end G - Connect the dots -->

<!-- start H - Islands -->
## H - Islands
### Time Limit: 8.0
| solution name | type |
|----|----|
|bf.cpp|WA|
|tubuann.cpp|AC|
|Luzhiled.cpp|AC|
###### updated 2020/09/05 20:56:43
<!-- end H - Islands -->

<!-- start I - Origami -->
## I - Origami
### Time Limit: 2.0
| solution name | type |
|----|----|
|wa.cpp|WA|
###### updated 2020/09/05 20:56:43
<!-- end I - Origami -->

<!-- start J - DEG MUL SUM -->
## J - DEG MUL SUM
### Time Limit: 2.0
| solution name | type |
|----|----|
|keymoon.cpp|AC|
|beet_naive.cpp|TLE|
|beet_tle.cpp|TLE|
###### updated 2020/09/05 20:56:43
<!-- end J - DEG MUL SUM -->

<!-- start K - Zor -->
## K - Zor
### Time Limit: 2.0
| solution name | type |
|----|----|
|wa.cpp|AC|
|tubuann.cpp|AC|
###### updated 2020/09/05 20:56:43
<!-- end K - Zor -->

<!-- start SpecialChat -->
## SpecialChat
### Time Limit: 2.0
| solution name | type |
|----|----|
|wa.cpp|WA|
###### updated 2020/09/05 20:56:43
<!-- end SpecialChat -->

<!-- end * -->

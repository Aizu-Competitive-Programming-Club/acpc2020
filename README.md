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
## [A - RTA] (A_RTA/info/info.toml)
### Time Limit: 2.0
| solution name | type |
|----|----|
|[wa.cpp](A_RTA/info/sol/wa.cpp)|WA|
|[beet.cpp](A_RTA/info/sol/beet.cpp)|AC|
|[shot.cpp](A_RTA/info/sol/shot.cpp)|AC|
|[keymoon.cpp](A_RTA/info/sol/keymoon.cpp)|AC|
|[Endered.cpp](A_RTA/info/sol/Endered.cpp)|AC|
|[ok.cpp](A_RTA/info/sol/ok.cpp)|AC|
###### updated 2020/09/07 18:13:44
<!-- end A - RTA -->

<!-- start B - LiChaoSegmentTree -->
## [B - LiChaoSegmentTree] (B_LiChaoSegmentTree/info/info.toml)
### Time Limit: 2.0
| solution name | type |
|----|----|
|[wa.cpp](B_LiChaoSegmentTree/info/sol/wa.cpp)|WA|
|[Endered.cpp](B_LiChaoSegmentTree/info/sol/Endered.cpp)|AC|
|[Luzhiled.cpp](B_LiChaoSegmentTree/info/sol/Luzhiled.cpp)|AC|
|[shot.cpp](B_LiChaoSegmentTree/info/sol/shot.cpp)|AC|
|[keymoon.cpp](B_LiChaoSegmentTree/info/sol/keymoon.cpp)|AC|
###### updated 2020/09/07 18:13:44
<!-- end B - LiChaoSegmentTree -->

<!-- start C - Broken Machine -->
## [C - Broken Machine] (C_BrokenMachine/info/info.toml)
### Time Limit: 2.0
| solution name | type |
|----|----|
|[self_loop.cpp](C_BrokenMachine/info/sol/self_loop.cpp)|WA|
|[extra_out.cpp](C_BrokenMachine/info/sol/extra_out.cpp)|WA|
|[Endered.cpp](C_BrokenMachine/info/sol/Endered.cpp)|AC|
###### updated 2020/09/07 18:13:44
<!-- end C - Broken Machine -->

<!-- start D - P -->
## [D - P] (D_P/info/info.toml)
### Time Limit: 2.0
| solution name | type |
|----|----|
|[wa.cpp](D_P/info/sol/wa.cpp)|WA|
|[correct2.cpp](D_P/info/sol/correct2.cpp)|AC|
|[Endered.cpp](D_P/info/sol/Endered.cpp)|AC|
|[keymoon.cpp](D_P/info/sol/keymoon.cpp)|AC|
###### updated 2020/09/07 18:13:44
<!-- end D - P -->

<!-- start E - Monochrome Stone -->
## [E - Monochrome Stone] (E_MonochromeStone/info/info.toml)
### Time Limit: 2.0
| solution name | type |
|----|----|
|[wa.cpp](E_MonochromeStone/info/sol/wa.cpp)|WA|
|[Endered.cpp](E_MonochromeStone/info/sol/Endered.cpp)|AC|
|[toyama.cpp](E_MonochromeStone/info/sol/toyama.cpp)|AC|
|[Luzhiled.cpp](E_MonochromeStone/info/sol/Luzhiled.cpp)|AC|
|[keymoon.cpp](E_MonochromeStone/info/sol/keymoon.cpp)|AC|
|[keymoon_wa.cpp](E_MonochromeStone/info/sol/keymoon_wa.cpp)|WA|
|[tubuann.cpp](E_MonochromeStone/info/sol/tubuann.cpp)|AC|
|[tubuann_TLE.cpp](E_MonochromeStone/info/sol/tubuann_TLE.cpp)|TLE|
|[tubuann_TLE_fast.cpp](E_MonochromeStone/info/sol/tubuann_TLE_fast.cpp)|TLE|
###### updated 2020/09/07 18:13:44
<!-- end E - Monochrome Stone -->

<!-- start F - LotOfMountains -->
## [F - LotOfMountains] (F-LotOfMountains/info/info.toml)
### Time Limit: 2.0
| solution name | type |
|----|----|
|[wa-1e-5.cpp](F-LotOfMountains/info/sol/wa-1e-5.cpp)|WA|
|[tle.cpp](F-LotOfMountains/info/sol/tle.cpp)|TLE|
|[heuristic.cpp](F-LotOfMountains/info/sol/heuristic.cpp)|WA|
|[rel-1e-7.cpp](F-LotOfMountains/info/sol/rel-1e-7.cpp)|AC|
|[tubuann.cpp](F-LotOfMountains/info/sol/tubuann.cpp)|AC|
|[tubuann_float.cpp](F-LotOfMountains/info/sol/tubuann_float.cpp)|WA|
###### updated 2020/09/07 18:13:44
<!-- end F - LotOfMountains -->

<!-- start G - Connect the dots -->
## [G - Connect the dots] (G_Connect_the_dots/info/info.toml)
### Time Limit: 2.0
| solution name | type |
|----|----|
|[wa.cpp](G_Connect_the_dots/info/sol/wa.cpp)|WA|
###### updated 2020/09/07 18:13:44
<!-- end G - Connect the dots -->

<!-- start H - Islands -->
## [H - Islands] (H_Islands/info/info.toml)
### Time Limit: 8.0
| solution name | type |
|----|----|
|[bf.cpp](H_Islands/info/sol/bf.cpp)|WA|
|[tubuann.cpp](H_Islands/info/sol/tubuann.cpp)|AC|
|[Luzhiled.cpp](H_Islands/info/sol/Luzhiled.cpp)|AC|
###### updated 2020/09/07 18:13:44
<!-- end H - Islands -->

<!-- start I - Origami -->
## [I - Origami] (I_Origami/info/info.toml)
### Time Limit: 2.0
| solution name | type |
|----|----|
|[wa.cpp](I_Origami/info/sol/wa.cpp)|WA|
###### updated 2020/09/07 18:13:44
<!-- end I - Origami -->

<!-- start J - DEG MUL SUM -->
## [J - DEG MUL SUM] (J_DEG_MUL_SUM/info/info.toml)
### Time Limit: 2.0
| solution name | type |
|----|----|
|[keymoon.cpp](J_DEG_MUL_SUM/info/sol/keymoon.cpp)|AC|
|[beet_naive.cpp](J_DEG_MUL_SUM/info/sol/beet_naive.cpp)|TLE|
|[beet_tle.cpp](J_DEG_MUL_SUM/info/sol/beet_tle.cpp)|TLE|
###### updated 2020/09/07 18:13:44
<!-- end J - DEG MUL SUM -->

<!-- start K - Zor -->
## [K - Zor] (K_Zor/info/info.toml)
### Time Limit: 2.0
| solution name | type |
|----|----|
|[wa.cpp](K_Zor/info/sol/wa.cpp)|AC|
|[tubuann.cpp](K_Zor/info/sol/tubuann.cpp)|AC|
###### updated 2020/09/07 18:13:44
<!-- end K - Zor -->

<!-- start SpecialChat -->
## [SpecialChat] (SpecialChat/info/info.toml)
### Time Limit: 2.0
| solution name | type |
|----|----|
|[wa.cpp](SpecialChat/info/sol/wa.cpp)|WA|
###### updated 2020/09/07 18:13:44
<!-- end SpecialChat -->

<!-- end * -->

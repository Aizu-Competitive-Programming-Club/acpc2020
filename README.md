# acpc2020


### 準備
```
pip install -r requirements.txt
```

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

### Pros
- 制約を一元管理
- サンプルの自動挿入
- CI

### Cons
- 誤差ジャッジ　ない
- C++ だけ

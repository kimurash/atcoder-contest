# atcoder_comp

## AtCoderへのログイン
- ログイン
```
$ acc login
$ oj login https://atcoder.jp/
```
- ログアウト
```
$ acc logout
```
- ログイン状態か確認する．
```
$ acc session
```
- accとojが連携できているか確認
```
$ acc check-oj
online-judge-tools is available.
```

## 解答の流れ
### コンテスト用ディレクトリを作成する
```
$ acc new abc101
```
問題の一覧が表示されるのでテストケースを
ダウンロードする問題を選択する．

### テストケースの実行
敢えて`-o`を付けてコンパイルした場合を例示
- コンパイル
```
$ g++ -o main.out main.cpp
```
- テスト
```
$ oj t -c "./main.out" -d ./tests/
```
- `-c`: 各サンプルケースに対して実行するコマンド
- `-d`: サンプルケースが存在するディレクトリ

### 問題を提出する
```
$ acc submit main.cpp
```
提出するファイルが格納されているディレクトリから
提出先を自動で判別してくれる．

### 問題用ディレクトリを追加する
```
$ acc add
```
- 再び問題を選択する画面になる．
- 既にディレクトリが作成されている問題は選択できない．

## 参考
- [atcoder-cli インストールガイド](http://tatamo.81.la/blog/2018/12/07/atcoder-cli-installation-guide/)
- [Getting Started for oj command](https://github.com/online-judge-tools/oj/blob/master/docs/getting-started.ja.md)
- [AtCoderのローカル自動テスト環境を構築した](https://writerman.hatenablog.jp/entry/2021/12/16/000655)

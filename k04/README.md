# 課題4 レポート

bb35319020 京岡龍樹
## 課題

[../sample/heights.csv]は標本全体（男性と女性合わせた14人）のデータをまとめたものである．
一方，[../sample/IDs.csv]は標本14人の学籍番号（身長データと同じ順番）である．
学籍番号を尋ねて，その学籍番号のデータがリストにあれば，学籍番号，身長，性別のデータを表示し，リストになければ，「No data」と表示せよ．

この二つのファイルを読み取り，学籍番号，身長，性別の3つをメンバーとする構造体の配列で管理するとよい．

## ソースコードの説明
6~10構造体の定義

45~48性別と身長を構造体の中に格納する

58~61IDを構造体の中に格納する

64~65IDを調べる

69~85該当するIDがあれば性別を調べる

該当するIDがなければNO dateと表記させる

## 入出力結果

例えば，ID 45313125のデータを調べたいとき，

```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313125
---
ID : 45313125
gender : Female
height : 152.4
```

例えば，ID 45313124のデータを調べたいとき，

```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313124
---
No data
```

## 修正履歴
[comment #20200722]
- DATE ではなく DATA ではないですか?
- l.9 IDは整数なので int型が良いです.  
合わせて, l.71を適切な書式指定子にしましょう
- l.10, l.22 末尾に`;`がありません
- l.51 if文ブロックの開始をしめす `{` がありません
- l.46,47,59 sscanf の f が抜けています
- l.47 %.lf -> %lf
- while条件分の終了カッコ `)` がありません
- l.67 for文の条件分の区切り文字が一部おかしいです. `;` であるべきところが `,` になっています. 
- l.71 dateというメンバ変数はありません
- l.80 &をつけると番地を指し示してしまいます. 
- heights, gender 変数は使用していないので消しましょう
- 上記の点を修正しても, 実行結果は正しくありませんでした. 
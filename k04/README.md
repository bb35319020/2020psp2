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
 input the filename of sample: ../sample/heights.csv
the filename of sample :../sample/heights.csv
input the filename of sample: ../sample/IDs.csv
the filename of sample :../sample/IDs.csv
which ID's do you want?:45313125
---
ID:45313125
gender:female
heights:152.4
```

例えば，ID 45313124のデータを調べたいとき，

```
input the filename of sample: ../sample/heights.csv
the filename of sample :../sample/heights.csv
input the filename of sample: ../sample/IDs.csv
the filename of sample :../sample/IDs.csv
which ID's do you want?:45313124
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

[comment #20200729 sonoda]
- TAの指摘した点を修正すること．
- heights.csvからfgetsでbuf1に1行コピーして，そのbuf1からsscanfでgenderとheightsを読み取るところ．
  - 察するに1回目のsscanfでgender, 2回目のsscanfでheightsを読み取りたいようですが，残念ながら，1回目の読み取りのあとにその続きから読んでくれるわけではなく，第1引数（アドレス）から読み始めます．
  - scanfの場合は前回の続きからですが，sscanfはそこが少し違います．
  - 1度で読み取らないといけません．`sscanf(buf1, "%d, %lf", &data[i].gender, &data[i].heights);`にしないといけません．

[comment #20200731]
- l.9 ID を int型にしましょう
- l.47 %f -> %lf  
- l.47 "%d`"`,`"`%f" -> "%d, %`l`f"
- l.68 %lf -> %d  
data -> data[i].ID
- heights, gender 変数は使用していないので消しましょう
- 上記の点を修正するとコンパイルエラーはなくなります, 実行結果はまだ正しくありません.

[comment #20200731_2]
- 今のプログラムでは最後の人(45318088)を調べたとき, 正しいIDが表示されません. heights.csvの1行目は有効なデータでないため, 2行目からdataに入れるようにしましょう.  
    - data[i].genderやdata[i].heights に値を入れていくwhile文に入る前に, 1度 fgets をすれば, while文の中では2行目のデータからdata[i]に入れていけると思います. 

[comment #20200804 sonoda]
- このレポートの入出力結果が誤っています．45313125の人は女性で152.4です．
- 63行目のfor文は，i<14 ではないでしょうか．data[14].ID　はメモリを超えています．ちなみにこの「14」のような数字は関数の中では使わないほうがよいです．変わりに，ソースコード冒頭で
  ```
  #define N 14
  ```
  などとしておいて，
  ```
  struct DATA data[N];
  ```
  や
  ```
  for(i=0;i<N;i++)
  ```
  などとします．

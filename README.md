# Log Filter（C++17 CLI ツール）

![Build](https://github.com/acc-vcc/log-filter-sample/actions/workflows/build.yml/badge.svg)

C++17 と CMake を使用して作成した、ログファイルの簡易フィルタリングツールです。  
標準入力またはファイルからログを読み込み、指定したログレベル（INFO / WARN / ERROR）の行のみを抽出します。

小規模な CLI ツール開発のサンプルとして利用でき、  
C++ の基本的な文字列処理・ファイル入出力・CMake 構成・GitHub Actions を含む  
最小構成のプロジェクト例となっています。

---

## 🛠 使用技術

- **C++17**
- **CMake（アウトオブソースビルド）**
- **std::filesystem による実行ファイル名取得**
- **GitHub Actions（自動ビルド & 簡易テスト）**

---

## 📌 機能概要

- ログレベルによる行フィルタリング  
  - 対応レベル：`INFO` / `WARN` / `ERROR`
- ファイル入力または標準入力に対応
- Usage 表示（`argv[0]` から実行名を自動取得）
- シンプルで読みやすい C++17 コード構成

---

## 🧩 実装ポイント

- `std::getline` による高速な行処理  
- `\n` を使用した効率的な出力（`std::endl` は未使用）  
- `std::filesystem::path` による実行ファイル名の抽出  
- エラー時には Usage を併記し、CLI ツールとして扱いやすい設計  
- GitHub Actions による自動ビルドと簡易テストを実装

---

## 📁 ディレクトリ構成

```
log-filter-sample/
├─ .gitignore             # Git 管理対象外ファイル設定
├─ .github/
│  └─ workflows/
│     └─ build.yml        # 自動ビルド用 GitHub Actions ファイル
├─ src/
│  └─ main.cpp            # メイン処理
├─ CMakeLists.txt         # CMake 設定
├─ LICENSE                # ライセンスファイル
└─ README.md              # プロジェクト説明
```

---

## ▶️ 使用方法

```
logfilter --level LEVEL [file]
```

### LEVEL（指定可能なログレベル）
- `INFO`
- `WARN`
- `ERROR`

### ファイルを指定する場合

```
logfilter --level ERROR app.log
```

---

## 📌 入力例

```
[INFO]  Starting system
[WARN]  Low memory
[ERROR] Failed to load module
[INFO]  Running task
```

### コマンド

```
logfilter --level ERROR app.log
```

### 出力

```
[ERROR] Failed to load module
```

---

## 📂 ビルド方法

### CMake を使用する場合

```
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
```

生成物は以下に出力されます：

```
build/logfilter
```


---

## 🧪 GitHub Actions（CI）

本リポジトリには以下を行う GitHub Actions を含みます：

- CMake による自動ビルド  
- 標準入力を用いた簡易テスト  
- main ブランチへの push / PR 時に実行  

---

## 📄 License

MIT License

---

## 📫 連絡について

ご相談やご依頼がありましたら、以下のメールアドレスまでご連絡ください。

**📧 acc.vcc.work@gmail.com**

丁寧に対応いたします。

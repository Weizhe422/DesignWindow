# DesignWindow - Qt文字編輯器

這是一個使用Qt6開發的文字編輯器應用程式，具有深色主題介面和完整的檔案操作功能。

## Qt專案檔案位置

本專案包含以下Qt相關檔案：

### 主要專案檔案

| 檔案名稱 | 路徑 | 說明 |
|---------|------|------|
| **Designwindow.pro** | `/Designwindow.pro` | Qt專案設定檔（.pro檔） |
| **ui_mainwindow.ui** | `/ui_mainwindow.ui` | Qt Designer UI設計檔 |
| **mainwindow.h** | `/mainwindow.h` | 主視窗標頭檔 |
| **mainwindow.cpp** | `/mainwindow.cpp` | 主視窗實作檔 |
| **main.cpp** | `/main.cpp` | 程式進入點 |

### UI生成檔案

| 檔案名稱 | 路徑 | 說明 |
|---------|------|------|
| **ui_ui_mainwindow.h** | `/ui_ui_mainwindow.h` | 從ui_mainwindow.ui自動生成的標頭檔 |

### 資源檔案

| 檔案名稱 | 路徑 | 說明 |
|---------|------|------|
| **designwindow.qrc** | `/images/images/designwindow.qrc` | Qt資源檔（包含所有圖示） |

### 圖示資源（位於 /images/images/ 目錄）

- `new.png` - 新增檔案圖示
- `open.png` - 開啟檔案圖示
- `save.png` - 儲存圖示
- `asave.png` - 另存新檔圖示
- `cut.png` - 剪下圖示
- `copy.png` - 複製圖示
- `paste.png` - 貼上圖示
- `undo.png` - 復原圖示
- `find.png` - 尋找圖示
- `editor.png` - 編輯器圖示

## 開發環境需求

- **Qt版本**: Qt 6.x
- **編譯器**: 支援C++17的編譯器
- **建置工具**: qmake 或 Qt Creator

## 如何建置專案

### 方法一：使用Qt Creator（推薦）

1. 開啟Qt Creator
2. 點選「File」→「Open File or Project...」
3. 選擇 `Designwindow.pro` 檔案
4. 點選「Configure Project」設定專案
5. 按下「Build」按鈕（Ctrl+B）建置專案
6. 按下「Run」按鈕（Ctrl+R）執行程式

### 方法二：使用命令列（qmake）

```bash
# 生成Makefile
qmake Designwindow.pro

# 編譯專案
make

# 執行程式（Windows）
.\debug\Designwindow.exe

# 執行程式（Linux/macOS）
./Designwindow
```

## 專案結構說明

```
DesignWindow/
├── Designwindow.pro          # Qt專案檔
├── main.cpp                  # 程式進入點
├── mainwindow.h              # 主視窗標頭檔
├── mainwindow.cpp            # 主視窗實作
├── ui_mainwindow.ui          # UI設計檔
├── ui_ui_mainwindow.h        # 自動生成的UI標頭檔
├── images/
│   └── images/
│       ├── designwindow.qrc  # Qt資源檔
│       ├── new.png
│       ├── open.png
│       ├── save.png
│       ├── asave.png
│       ├── cut.png
│       ├── copy.png
│       ├── paste.png
│       ├── undo.png
│       ├── find.png
│       └── editor.png
├── 功能說明.md               # 功能說明文件（繁體中文）
└── FEATURE_DOCUMENTATION.md  # 功能說明文件（英文）
```

## 主要功能

### 檔案操作
- **新增檔案**：建立新的文字檔案
- **開啟檔案**：開啟現有的文字檔案
- **儲存檔案** (Ctrl+S)：儲存當前檔案
- **另存新檔**：將檔案儲存到新位置

### 編輯功能
- **剪下** (Ctrl+X)：剪下選取的文字
- **複製** (Ctrl+C)：複製選取的文字
- **貼上** (Ctrl+V)：貼上剪貼簿內容
- **復原** (Ctrl+Z)：復原上一步操作
- **尋找** (Ctrl+F)：搜尋文字內容

### 介面特色
- **深色主題**：護眼的深色介面設計
- **等寬字型**：適合程式碼編輯的字型
- **狀態列**：顯示操作狀態和檔案資訊

## 技術文件

詳細的功能說明請參閱：
- [功能說明.md](功能說明.md) - 繁體中文詳細說明
- [FEATURE_DOCUMENTATION.md](FEATURE_DOCUMENTATION.md) - 英文詳細說明

## Qt檔案說明

### .pro檔案（專案檔）
`Designwindow.pro` 是Qt專案的核心設定檔，定義了：
- 使用的Qt模組（core, gui, widgets）
- 原始碼檔案（.cpp）
- 標頭檔（.h）
- UI檔案（.ui）
- 資源檔（.qrc）

### .ui檔案（介面設計檔）
`ui_mainwindow.ui` 是使用Qt Designer設計的視覺化介面檔案，包含：
- 視窗佈局
- 選單結構
- 工具列按鈕
- 各種元件的屬性

### .qrc檔案（資源檔）
`images/images/designwindow.qrc` 定義了專案使用的圖片資源，讓圖示可以嵌入到執行檔中。

## 常見問題

### Q: 為什麼找不到Qt檔案？
A: 所有Qt檔案都在專案根目錄，請參考上方的「Qt專案檔案位置」表格。資源檔（.qrc）位於 `images/images/` 子目錄中。

### Q: 如何修改介面設計？
A: 使用Qt Creator開啟 `ui_mainwindow.ui` 檔案，就可以使用視覺化設計器編輯介面。

### Q: 如何新增圖示？
A: 
1. 將圖片檔案放到 `images/images/` 目錄
2. 編輯 `designwindow.qrc` 檔案，加入新的圖片檔案
3. 在UI設計中就可以使用新的圖示

## 授權

本專案使用Qt框架，請遵守Qt的相關授權條款。

## 聯絡資訊

如有問題或建議，歡迎開啟Issue討論。

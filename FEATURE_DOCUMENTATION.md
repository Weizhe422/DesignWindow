# DesignWindow Feature Documentation

## Overview
This document provides a detailed explanation of three core features recently implemented in the DesignWindow application: **Save**, **Save As**, and **Text Editor**.

---

## 1. Save Function

### 1.1 Access Points
- **File Menu**: File(E) → Save(S)
- **Toolbar**: Save button (disk icon)
- **Shortcut**: `Ctrl+S`

### 1.2 Code Implementation
```cpp
void MainWindow::onSaveTriggered()
{
    if (currentFilePath.isEmpty()) {
        // If no current file path exists, call Save As
        onSaveAsTriggered();
    } else {
        // Save to current file
        saveToFile(currentFilePath);
    }
}
```

### 1.3 Functionality Description
The **Save function** implements an intelligent file-saving mechanism with the following logic:

1. **Check Current File Path**:
   - Checks the `currentFilePath` member variable
   - This variable stores the path of the currently edited file

2. **Smart Decision Making**:
   - **Scenario A - First Save**: If `currentFilePath` is empty (indicating a new document or never saved), automatically triggers the "Save As" dialog
   - **Scenario B - Existing File**: If a file path exists, directly overwrites the file

3. **Use Cases**:
   - Quick save of open documents
   - No need to reselect save location
   - Ideal for frequently saving work progress

### 1.4 Design Advantages
- **Intelligent**: Automatically determines whether to show file chooser dialog
- **Efficient**: Quick overwrite save for existing files
- **User-friendly**: Follows standard text editor conventions

---

## 2. Save As Function

### 2.1 Access Points
- **File Menu**: File(E) → Save As(A)
- **Toolbar**: Save As button (disk icon variant)

### 2.2 Code Implementation
```cpp
void MainWindow::onSaveAsTriggered()
{
    QString fileName = QFileDialog::getSaveFileName(
        this,
        tr("另存檔案"),
        "",
        tr("文字檔案 (*.txt);;所有檔案 (*.*)")
    );
    
    if (!fileName.isEmpty()) {
        saveToFile(fileName);
        currentFilePath = fileName;
    }
}
```

### 2.3 Functionality Description
The **Save As function** provides a complete file-saving dialog that allows users to:

1. **Open File Chooser Dialog**:
   - Uses Qt's `QFileDialog::getSaveFileName()` method
   - Dialog title displays "另存檔案" (Save File As)

2. **Choose Save Location and Filename**:
   - User can browse the file system
   - Freely input a new filename
   - Select the destination directory

3. **File Type Filtering**:
   - Provides two file type options:
     - `文字檔案 (*.txt)`: Default option for text content
     - `所有檔案 (*.*)`: Allows any file extension

4. **Save and Update Path**:
   - If user confirms save (doesn't cancel):
     - Calls `saveToFile()` to perform actual save
     - Updates `currentFilePath` to the new file path

### 2.4 Use Cases
- Save document as a new file
- Create document copies in different locations
- Save document with different filename
- First-time save of newly created document

### 2.5 Design Advantages
- **Flexibility**: Free choice of save location and filename
- **Safety**: Won't overwrite original file (unless user explicitly chooses)
- **File Type Support**: Supports multiple file formats

---

## 3. Shared Save Mechanism

### 3.1 Core Save Function
```cpp
void MainWindow::saveToFile(const QString &filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, tr("儲存錯誤"), 
                           tr("無法儲存檔案: %1").arg(file.errorString()));
        return;
    }
    
    QTextStream out(&file);
    out << textEdit->toPlainText();
    
    statusbar->showMessage(tr("檔案已儲存: %1").arg(filePath), 3000);
}
```

### 3.2 Functionality Description
**saveToFile()** is the underlying save function shared by both Save and Save As:

1. **Open File**:
   - Creates `QFile` object
   - Uses `QIODevice::WriteOnly` mode (write-only)
   - Uses `QIODevice::Text` mode (text mode)

2. **Error Handling**:
   - If unable to open file (insufficient permissions, path doesn't exist, etc.)
   - Displays warning dialog explaining the error
   - Uses `file.errorString()` to get system error message

3. **Write Content**:
   - Uses `QTextStream` for text stream writing
   - Gets plain text content from `textEdit` widget (`toPlainText()`)
   - Writes content to file

4. **User Feedback**:
   - Displays success message in status bar
   - Shows actual saved file path
   - Message disappears automatically after 3 seconds

### 3.3 Design Advantages
- **Code Reuse**: Both functions share the same save logic
- **Comprehensive Error Handling**: Properly handles various save failure scenarios
- **User Feedback**: Real-time operation feedback via status bar

---

## 4. Text Editor Feature

### 4.1 Widget Information
- **Widget Type**: `QTextEdit`
- **Variable Name**: `textEdit`
- **Location**: Central area of main window

### 4.2 Code Implementation
```cpp
// Text editor dark theme style
QString textEditStyle = R"(
    QTextEdit {
        background-color: #1e1e1e;
        color: #e0e0e0;
        border: 1px solid #3d3d3d;
        selection-background-color: #404040;
        selection-color: #ffffff;
        font-family: "Consolas", "Monaco", "Courier New", monospace;
    }
)";

textEdit->setStyleSheet(textEditStyle);
```

### 4.3 Functionality Description
The **Text Editor** is the main content editing area, providing:

1. **Basic Editing Features**:
   - Text input and editing
   - Multi-line text support
   - Line breaks and formatting support

2. **Appearance Design - Dark Theme**:
   - **Background Color**: `#1e1e1e` (dark gray-black)
   - **Text Color**: `#e0e0e0` (light gray-white)
   - **Border Color**: `#3d3d3d` (medium gray, 1px solid)
   - **Selection Background**: `#404040` (medium-dark gray)
   - **Selection Text**: `#ffffff` (pure white)

3. **Font Settings**:
   - Uses monospace font
   - Priority order: Consolas → Monaco → Courier New
   - Suitable for code and text editing

4. **Integration with Save Functions**:
   - Content retrieved via `textEdit->toPlainText()`
   - Converts editor content to plain text format
   - Saves to file

### 4.4 User Experience Features
- **Eye-Friendly Design**: Dark theme reduces eye strain
- **Clear Contrast**: Sufficient contrast between text and background
- **Professional Look**: Monospace font suitable for structured content editing
- **Visual Consistency**: Unified with overall application dark theme

---

## 5. UI Element Definitions

### 5.1 Menu Structure (ui_mainwindow.ui)

#### File Menu
```xml
<widget class="QMenu" name="menu_E">
    <property name="title">
        <string>檔案(E)</string>
    </property>
    <addaction name="action_S"/>     <!-- Save -->
    <addaction name="action_A"/>     <!-- Save As -->
</widget>
```

#### Save Actions
```xml
<action name="action_S">
    <property name="icon">
        <iconset resource="images/images/designwindow.qrc">
            <normaloff>:/images/save.png</normaloff>
        </iconset>
    </property>
    <property name="text">
        <string>儲存(S)</string>
    </property>
    <property name="shortcut">
        <string>Ctrl+S</string>
    </property>
</action>

<action name="action_A">
    <property name="icon">
        <iconset resource="images/images/designwindow.qrc">
            <normaloff>:/images/asave.png</normaloff>
        </iconset>
    </property>
    <property name="text">
        <string>另存(A)</string>
    </property>
</action>
```

### 5.2 Signal-Slot Connections (mainwindow.cpp)
```cpp
// Connect Save and Save As actions
connect(action_S, &QAction::triggered, this, &MainWindow::onSaveTriggered);
connect(action_A, &QAction::triggered, this, &MainWindow::onSaveAsTriggered);
```

**Explanation**:
- When `action_S` is triggered, calls `onSaveTriggered()` slot function
- When `action_A` is triggered, calls `onSaveAsTriggered()` slot function
- Uses Qt's signal-slot mechanism for event handling

---

## 6. Data Members

### 6.1 MainWindow Class Definition (mainwindow.h)
```cpp
class MainWindow : public QMainWindow, public Ui_MainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onSaveTriggered();      // Save slot function
    void onSaveAsTriggered();    // Save As slot function

private:
    QString currentFilePath;     // Current file path
    void saveToFile(const QString &filePath);  // Save function
};
```

### 6.2 Member Description

#### `currentFilePath` (QString)
- **Purpose**: Stores the complete path of currently edited file
- **Initial Value**: Empty string (new document)
- **Update Timing**:
  - Updated after Save As execution to new file path
  - Updated after opening file to opened file path
- **Functions**:
  - Determines whether to show Save As dialog
  - Provides target path for quick save
  - Displays current file information in status bar

---

## 7. Visual Style System

### 7.1 Dark Theme Design Philosophy
The entire application adopts a consistent dark theme, providing:
- **Reduced Eye Strain**: Suitable for extended use
- **Professional Appearance**: Similar to modern IDEs and editors
- **Visual Harmony**: All components use unified color scheme

### 7.2 Color Scheme
```cpp
// Primary color definitions
#1e1e1e  // Main background (dark gray-black)
#2d2d2d  // Menu background (medium-dark gray)
#3d3d3d  // Border and separator (medium gray)
#404040  // Selection background (medium-bright gray)
#e0e0e0  // Main text color (light gray-white)
#ffffff  // Highlight text color (pure white)
```

### 7.3 Application Scope
- **Main Window Background**: #1e1e1e
- **Menu Bar**: Gradient background (#2d2d2d to #1a1a1a)
- **Text Editor**: #1e1e1e background, #e0e0e0 text
- **Status Bar**: #2d2d2d background, #3d3d3d top border

---

## 8. Technical Features Summary

### 8.1 Qt Classes Used
1. **QFileDialog**: Provides file chooser dialog
2. **QFile**: Handles file read/write operations
3. **QTextStream**: Text stream processing
4. **QMessageBox**: Displays error and warning messages
5. **QTextEdit**: Multi-line text editing widget
6. **QAction**: Menu and toolbar actions
7. **QStatusBar**: Status bar message display

### 8.2 Design Patterns
- **Signal-Slot Mechanism**: Implements decoupled event handling
- **Shared Function Design**: `saveToFile()` reused by multiple features
- **Smart Decision Logic**: Save function automatically determines operation

### 8.3 Error Handling
- Displays error message when file open fails
- Provides specific error reason description
- Prevents application crash

### 8.4 User Experience
- Real-time status feedback (status bar messages)
- Standard keyboard shortcuts (Ctrl+S)
- Follows mainstream editor conventions
- Visual consistency (dark theme)

---

## 9. Usage Flow Examples

### Example 1: First-time Save of New Document
1. User inputs content in `textEdit`
2. Presses `Ctrl+S` or clicks Save button
3. Since `currentFilePath` is empty, automatically triggers Save As dialog
4. User selects save location and filename (e.g., `C:\Documents\my_file.txt`)
5. Program writes text content to file
6. `currentFilePath` updates to `C:\Documents\my_file.txt`
7. Status bar displays "檔案已儲存: C:\Documents\my_file.txt"

### Example 2: Save After Editing Existing Document
1. User modifies already opened document content
2. Presses `Ctrl+S`
3. Since `currentFilePath` has value, directly overwrites save
4. No need to reselect file
5. Status bar displays confirmation message

### Example 3: Save As New File
1. User wants to preserve original file after editing
2. Clicks "File" → "Save As(A)"
3. Enters new filename in dialog (e.g., `my_file_v2.txt`)
4. Program saves content to new file
5. `currentFilePath` updates to new file path
6. Subsequent Save operations will save to new file

---

## 10. Future Enhancements

### 10.1 Suggested Feature Improvements
1. **Auto-Save**: Periodic automatic save functionality
2. **Pre-Save Confirmation**: Ask whether to save when file is modified
3. **Recent Files**: Record list of recently opened files
4. **File Change Detection**: Detect if file was modified by external program
5. **Encoding Selection**: Support different text encodings (UTF-8, Big5, etc.)

### 10.2 Potential Improvements
1. **Undo/Redo**: Integrate more comprehensive edit history management
2. **Multi-File Support**: Tabbed editing of multiple documents
3. **Syntax Highlighting**: Provide syntax coloring based on file type

---

## Conclusion

This implementation provides a complete, user-friendly text editing and file-saving system. Through the tight integration of **Save**, **Save As**, and **Text Editor** core functions, it delivers a professional text editor-like user experience.

**Main Advantages**:
- ✅ Intelligent save logic
- ✅ Comprehensive error handling
- ✅ Unified dark visual style
- ✅ Intuitive user operations
- ✅ Well-organized code structure

These features establish a solid foundation for the DesignWindow application, enabling it to function as a practical text editing tool.

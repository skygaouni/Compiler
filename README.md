# NCKU Compiler

這個專案包含三份課程作業，分別實作了一個簡單編譯器的三個主要階段：  
1. **Lexical Analysis (Scanner)**  
2. **Syntactic Analysis (Parser)**  
3. **Code Generation (Jasmin → JVM Bytecode)**  

完成三份作業後，最終結果會是一個可以執行的簡易 Compiler。  

---

## 📂 Homework 1: Lexical Analysis (Scanner)

**目標**  
- 使用 `flex` 撰寫一個 **Scanner**，將原始程式碼轉換成一連串的 **Token**。  
- 掃描輸入程式，辨識關鍵字、變數名稱、常數、運算符號等。  

**重點**  
- 線性分析 (Linear Analysis)  
- 輸出 Token 序列，作為 Parser 的輸入。  

**檔案結構** 
``` 
hw1/
├── scanner.l # flex 規則檔
├── Makefile
├── input/ # 測資
├── answer/ # 標準答案
└── ...
```

---

## 📂 Homework 2: Syntactic Analysis (Parser)

**目標**  
- 使用 `bison (yacc)` 撰寫一個 **Parser**，檢查程式碼的語法是否正確。  
- 依據定義好的文法 (Grammar)，將 Token 組合成語法樹 (Parser Tree)。  

**重點**  
- 階層式分析 (Hierarchical Analysis)  
- 文法設計 (BNF / CFG)  
- 輸出語法解析順序與變數作用域 (Scope) 表格。  
- 避免 Shift-Reduce Conflict。  

**檔案結構**  
```
hw2/
├── compiler.y # bison (yacc) 規則檔
├── Makefile
└── ...
```

---

## 📂 Homework 3: Code Generation (Jasmin)

**目標**  
- 在前兩份作業的基礎上，將程式轉換成 **Jasmin Assembly**，再交給 JVM 執行。  
- 最後產生 `.class` 檔，能直接在 Java 虛擬機器上執行。  

**重點**  
- 語意動作輸出的語法順序，轉換成 Jasmin 指令。  
- 支援算術運算、邏輯判斷、變數存取、if/else、迴圈、函數呼叫等。  
- 使用 `CODEGEN` 巨集或 `fprintf` 將 Jasmin code 輸出到 `Main.j`。  

**檔案結構**  
```
hw3/
├── compiler.l
├── compiler.y
├── compiler_common.h
├── Makefile
└── ...
```
---

## 🏁 最終成果

三個作業合起來，構成了一個小型編譯器，完整涵蓋了編譯器的主要階段：

1. **前端 (Front-end)**  
   - HW1: Lexical Analysis  
   - HW2: Syntax Analysis  

2. **後端 (Back-end)**  
   - HW3: Code Generation → JVM Bytecode  

完成 HW3 後，輸出的 Java Bytecode 可以直接交給 JVM 執行，正式得到一個可用的 Compiler 🚀
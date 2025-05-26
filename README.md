# 題型

眾所皆知，CMS 有 4 種不一樣的題型，分別是 Batch, Communication, OutputOnly 和 TwoSteps。  

## Batch
在一般的 Online judge 上大多數的題目都屬於此類，大多數都是由標準輸入讀入資料，再根據你的標準輸出給分。

### grader
在 OI 上，有些題目會幫你寫好一部分的程式碼，而你只要寫題目要你寫的那個部分就好，通常都是要你實作某些函式然後回傳某些東西，簡單來說就是輸入會以函式參數的形式給你，而你要回傳某些東西作為輸出。

## Communication
也就是互動題，某些 Online judge 偶爾會出現。  

互動題常見有兩種互動方式，一種是以標準輸入輸出互動，大多數 Online judge 的互動題都屬於此類。

另一種是以函式的方式互動，和有 grader 的 Batch 題差不多，大概就是你在實作函式時可以呼叫一個題目幫你寫好的函式來獲取某些資訊。

## OutputOnly
簡單來說就是給你測資，你只要對每筆測資上傳答案就好。

## TwoSteps
通常是要上傳兩個檔案，評測系統會將測資傳入第一個檔案，你要根據題目的要求做一些操作後回傳一個東西，然後評測系統會執行第二個檔案，這個檔案的輸入會和你第一個檔案回傳的東西有關係，接著再回傳一些題目要求的東西。


# 實作細節

先假設各位都會用終端機編譯並執行程式碼了，不會的可以問別人。

通常題目會給你個 zip 檔，解壓縮裡面會有一些東西。

## grader
有 grader 的題目通常這個 zip 檔會給你範例 grader，這個範例 grader 可能和正式 grader 一樣，也可能完全不一樣。  

通常還會給一些可以正確編譯但不會 AC 的範例程式碼，你要實作時可以直接改這份 code 來寫。  

這個 zip 檔裡面也通常會有一個叫 compile_cpp.sh 之類的 sh 檔和一個叫 run_cpp.sh 之類的 sh 檔。  
如果你是用 linux 的作業系統直接在終端機上打 `./compile_cpp.sh` 就會幫你 compile 出一個檔案，接著再輸入 `./run_cpp.sh` 就可以執行了。通常會給你一些 examples，把裡面的東西貼上去就好，題序也通常會寫要怎麼用範例評分程式。

但相信大多數人的電腦都是 windows 作業系統的。    
第一種解決方法是去裝 WSL (Windows Subsystem for Linux)，這樣就可以用 linux 指令了。  
另一種方法是直接把 compile_cpp 裡的指令直接輸入終端機，舉例來說，cup 這題，本來是
```sh
#!/bin/bash
problem=cup
g++ -std=gnu++14 -O2 -pipe -static -o $problem grader.cpp $problem.cpp
```
你就可以把
```
g++ -std=gnu++14 -O2 -pipe -static -o cup grader.cpp cup.cpp
```
輸入終端機後就會幫你編譯出來了，假設編譯出來的檔案叫 cup.exe

接著在終端機輸入 `./cup.exe` 就可以執行了。

## OutputOnly
通常 OutputOnly 的測資都給在這個 zip 檔裡面，你可能會需要讀入這些測資。

你在程式加上
```cpp
freopen("01.in", "r", stdin);
freopen("output_01.txt", "w", stdout);
```
就可以以 "01.in" 作為標準輸入，然後把標準輸出的東西丟到 "output_01.txt" 裡面。

注意 01.in 這個檔案必須和這份程式碼的執行檔放在同一個資料夾下面才會正確讀取到。

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

// ログレベル定義
enum class Level {
    INFO,
    WARN,
    ERROR,
    UNKNOWN
};

// 引数からログレベル変換
Level parseLevel(const std::string& s) {
    if (s == "INFO")  return Level::INFO;
    if (s == "WARN")  return Level::WARN;
    if (s == "ERROR") return Level::ERROR;
    return Level::UNKNOWN;
}

// 該当レベルの文字列を含むか判定
bool containsLevel(const std::string& line, Level level) {
    switch (level) {
        case Level::INFO:  return line.find("[INFO]")  != std::string::npos;
        case Level::WARN:  return line.find("[WARN]")  != std::string::npos;
        case Level::ERROR: return line.find("[ERROR]") != std::string::npos;
        default: return false;
    }
}

// エントリポイント
int main(int argc, char* argv[]) {
    // 実行ファイル名取得
    std::string appName = std::filesystem::path(argv[0]).filename().string();

    if (argc < 3) {
        std::cerr << "Usage: " << appName << " --level LEVEL [file]\n"
                  << "  LEVEL = INFO | WARN | ERROR\n";
        return 1;
    }

    // 引数からログレベル変換
    std::string levelArg = argv[2];
    Level level = parseLevel(levelArg);

    if (level == Level::UNKNOWN) {
        std::cerr << "Unknown level: " << levelArg << "\n";
        std::cerr << "Usage: " << appName << " --level LEVEL [file]\n"
                  << " LEVEL = INFO | WARN | ERROR\n";
        return 1;
    }

    // ファイル指定していたらファイルから、していなかったら標準入力から読み込み
    std::istream* input = &std::cin;
    std::ifstream file;

    if (argc >= 4) {
        file.open(argv[3]);
        if (!file) {
            std::cerr << "Failed to open file: " << argv[3] << "\n";
            return 1;
        }
        input = &file;
    }

    // 各行処理
    std::string line;
    while (std::getline(*input, line)) {
        if (containsLevel(line, level)) {
            std::cout << line << '\n';
        }
    }

    return 0;
}

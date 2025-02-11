import nltk
from nltk.tokenize import word_tokenize, sent_tokenize
from nltk.corpus import stopwords
from nltk.stem import WordNetLemmatizer
import string

class NLPProcessor:
    """
    自然语言处理工具类
    提供基本的文本预处理、分词、词形还原等NLP功能
    """
    
    def __init__(self):
        """
        初始化NLP处理器
        下载必要的NLTK数据
        """
        try:
            nltk.download('punkt')
            nltk.download('stopwords') 
            nltk.download('wordnet')
            self.stop_words = set(stopwords.words('english'))
            self.lemmatizer = WordNetLemmatizer()
        except Exception as e:
            print(f"初始化NLP处理器时发生错误: {str(e)}")
    
    def preprocess_text(self, text):
        """
        文本预处理函数
        参数:
            text: 输入的文本字符串
        返回:
            处理后的单词列表
        """
        try:
            # 转换为小写
            text = text.lower()
            
            # 分句
            sentences = sent_tokenize(text)
            
            # 分词
            tokens = []
            for sentence in sentences:
                words = word_tokenize(sentence)
                tokens.extend(words)
            
            # 去除标点符号和停用词
            tokens = [token for token in tokens 
                     if token not in string.punctuation
                     and token not in self.stop_words]
            
            # 词形还原
            tokens = [self.lemmatizer.lemmatize(token) for token in tokens]
            
            return tokens
            
        except Exception as e:
            print(f"处理文本时发生错误: {str(e)}")
            return []

    def get_word_frequency(self, tokens):
        """
        统计词频
        参数:
            tokens: 单词列表
        返回:
            词频字典
        """
        try:
            freq_dict = {}
            for token in tokens:
                freq_dict[token] = freq_dict.get(token, 0) + 1
            return freq_dict
        except Exception as e:
            print(f"统计词频时发生错误: {str(e)}")
            return {}

# 使用示例
if __name__ == "__main__":
    # 创建NLP处理器实例
    nlp = NLPProcessor()
    
    # 示例文本
    sample_text = """Natural language processing (NLP) is a subfield of linguistics, 
    computer science, and artificial intelligence concerned with the interactions 
    between computers and human language."""
    
    # 处理文本
    processed_tokens = nlp.preprocess_text(sample_text)
    print("处理后的单词:", processed_tokens)
    
    # 统计词频
    word_freq = nlp.get_word_frequency(processed_tokens)
    print("\n词频统计:")
    for word, freq in word_freq.items():
        print(f"{word}: {freq}")

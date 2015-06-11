from pylearn2.datasets.adult_dataset import AdultDataset
import pickle

print 'convert: train.csv -> train.pkl'
pyln_data = AdultDataset('train.csv', one_hot=True)
pickle.dump(pyln_data, open('train.pkl', 'w'))

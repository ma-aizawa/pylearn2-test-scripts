from pylearn2.datasets.adult_dataset import AdultDataset
import pickle

print 'convert: test.csv -> test.pkl'
plyn_data = AdultDataset('test.csv', one_hot=True)
pickle.dump(pyln_data, open('test.pkl', 'w'))


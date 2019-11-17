const ie = require('bindings')('InferenceEngineAddon');

const patToModel = '/home/atugarev/Developer/OpenVINO/deployment_tools/workbench_dev/workbench/resources/models/IR/classification/inception_v3/inception_v3.';

const ieNetwork = new ie.IENetwork(`${patToModel}xml`, `${patToModel}bin`);

console.log(ieNetwork.getBatchSize());

console.log(ieNetwork.size());
console.log(ieNetwork.getLayerByName('pool').getParamAsString('pool-method'));

(function() {

	'use strict';

    angular.module('jarvisApp.neuralNet').config(Config);

    function Config($translateProvider, $urlRouterProvider, $stateProvider) {

        var neuralNetearch = {
            name: "neuralNetearch",
            url: "/neuralNet",
            controller: 'neuralNetController',
            controllerAs: 'vm',
            templateUrl: "modules/neuralNet/neural_net.html"
        };
        var neuralNetEdit = {
            abstract: true,
            name: "neuralNetEdit",
            url: "/neuralNet/{id}",
            controller: 'neuralNetEditController',
            controllerAs: 'vm',
            templateUrl: "modules/neuralNet/neural_net.edit.html"
        };
        var neuralNetEditMain = {name: "neuralNetEdit.main",
            url: "",
            controller: 'neuralNetEditMainController',
            controllerAs: 'vm',
            templateUrl: "modules/neuralNet/neural_net.edit.main.html",
        };

        $stateProvider
            .state( neuralNetearch )
            .state( neuralNetEdit )
            .state( neuralNetEditMain )
        ;
    }


})();

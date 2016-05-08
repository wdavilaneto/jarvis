
(function () {

    'use strict';

    angular.module('jarvisApp.main').controller('MainController', MainController);
    function MainController($scope, $location,  ENV_CONFIG, toaster, $filter, $translate) {

        var self = this;

        // Public Metods

        this.envConfig = ENV_CONFIG;
    }

})();
